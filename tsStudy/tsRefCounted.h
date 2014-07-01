//
//  tsRefCounted.h
//  tsStudy
//
//  Created by signorinotang on 14-1-6.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef tsStudy_tsRefCounted_h
#define tsStudy_tsRefCounted_h

#include "tsAllocatedObject.h"
#include "tsAtomic.h"
#include <assert.h>

_ts_begin

class  RefCounted : public AllocatedObject {
public:
	RefCounted() : m_ref_count(1) {}
	RefCounted(const RefCounted &) : m_ref_count(1) {
        
    }
	virtual ~RefCounted() {}
	
	RefCounted & operator =(const RefCounted &) { return *this; }
	
	int ref_count() const { return m_ref_count; }
	
	void grab() const {Atomic::increase(m_ref_count); }
	
	bool drop() const {
        assert(m_ref_count);
		if (!Atomic::decrease(m_ref_count)) {
			_release();
			return true;
		}
		return false;
	}
	
protected:
	virtual void _release() const { delete this; }
	
private:
	mutable Atomic::Int32 m_ref_count;
};


template <class _RefCounted>
class RefCountedPtr {
public:
    RefCountedPtr()
    : m_pointer(0) {}
    RefCountedPtr(_RefCounted* ptr)
    : m_pointer(ptr) {}
    RefCountedPtr(const RefCountedPtr& other)
    : m_pointer(other.m_pointer) {
        if(m_pointer) {
            m_pointer->grab();
        }
    }
    
    template <class T>
	RefCountedPtr(const RefCountedPtr<T> &rhs) : m_pointer(rhs.m_pointer) {
		if (m_pointer) {
			m_pointer->grab();
		}
	}
   
    ~RefCountedPtr() {
        release();
    }
    
    void swap(RefCountedPtr &rhs) {
        _RefCounted* t = rhs.m_pointer;
        rhs.m_pointer = m_pointer;
        m_pointer = t;
    }
    
    RefCountedPtr & operator = (const RefCountedPtr& rhs) {
        if(rhs.m_pointer != m_pointer) {
            RefCountedPtr t(rhs);
            swap(t);
        }
        return *this;
    }
    
    _RefCounted* operator ->() const {
        return  m_pointer;
    }
    
    _RefCounted operator *() const {
        return *m_pointer;
    }
    
    _RefCounted* ptr() const {
        return m_pointer;
    }
    
    bool null() const {
        return m_pointer == 0;
    }
    
    s32 ref_count() const {
        if(!m_pointer) {
            return 0;
        }
        return m_pointer->ref_count();
    }
    
    //dynamic_cast
    template <class T>
    RefCountedPtr<T> dyn_cast() const {
        T* p = dynamic_cast<T*> (m_pointer);
        if(p) {
            p->grab();
        }
        return p;
    }
    
    //static_cast
    template <class T>
    RefCountedPtr<T> cast() const {
        if(!m_pointer) {
            return RefCountedPtr<T>();
        }
        T *p = static_cast<T*>(m_pointer);
        p->grab();
        return p;
    }
    
    void release() {
        if(m_pointer) {
            m_pointer->drop();
            m_pointer = 0;
        }
    }
    
    static const RefCountedPtr kNull;
    
private:
    _RefCounted* m_pointer;
};

template <class _RefCounted>
const RefCountedPtr<_RefCounted> RefCountedPtr<_RefCounted>::kNull;

_ts_end

#define VN_SAFE_DROP(ptr) if(ptr) {ptr->drop(); ptr = 0;}

#endif
