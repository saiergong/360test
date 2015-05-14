#include "qh_string.h"
#include <stdexcept>

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
		if(s == NULL || strlen(s) == 0){
			data_ = NULL;
			len_ = 0;
		}
		else{
			len_ = strlen(s);
			data_ = new char[len_ + 1];
			if(data_ != 0){
				strncpy(data_, s, len_);
				*(data_ + len_) = 0;
			}
		}

    }

    string::string( const char* s, size_t len )
    {
	//	printf("hello\n");
		len_ = len;
		if(len <= 0){
			data_ = NULL;
		}
		else{
			data_ = new char[len_ + 1];
			if(data_ != NULL){
				strncpy(data_, s, len_);
				if(len_ > strlen(s)){
					memset(data_ + strlen(s), 0, len_ - strlen(s));
				}
				*(data_ + len_) = 0;
			}
		}
    }

    string::string( const string& rhs )
    {

		len_ = rhs.len_;
		if(len_ == 0)
			data_ = NULL;
		else
			data_ = new char[len_ + 1];
		if(data_ != NULL){
			strncpy(data_, rhs.data_, len_);
			*(data_ + len_) = 0;
		}
    }

    string& string::operator=( const string& rhs )
    {
		if(this == &rhs){
			return *this;
		}
		len_ = rhs.len_;
		if(len_ == 0)
			data_ = NULL;
		else
			data_ = new char[len_];
		if(data_ != NULL){
			strncpy(data_, rhs.data_, len_);
			*(data_ + len_) = 0;
		}
        return *this;
    }

    string::~string()
    {
		delete []data_;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }


    char& string::operator[]( size_t index )
    {
		if(index < 0 || index >= len_)
			throw std::out_of_range("out_of_range");
		return data_[index];
    }
}
