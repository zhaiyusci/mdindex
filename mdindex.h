#ifndef MDINDEX_H
#define MDINDEX_H
#include<vector>
#include<iostream>
class mdindex{
  const std::vector <size_t> max_; 
  // max number of each dimension, staring from 0
  std::vector <size_t> current_; 
  // current indices
  size_t totalindex_;
  public:
  template<typename T>
  mdindex(const std::vector <T> &max): max_(max.begin(), max.end()), current_(max.size(),0), totalindex_(0){ }

  mdindex(const mdindex& rhs):max_(rhs.max_), current_(rhs.current_), totalindex_(rhs.totalindex_){ }

  void reset(){
    for(size_t i=0; i!=current_.size(); ++i)current_[i]=0;
    totalindex_=0;
  }

  const size_t & current() const{
    return totalindex_;
  }

  const size_t & current(const unsigned int & i) const{
    return current_[i];
  }

  size_t max() const {
    unsigned int tmp(1);
    for(int i=0; i!= max_.size(); ++i) tmp*=max_[i];
    return tmp;
  }

  const size_t & max(const unsigned int & i) const {
    return max_[i];
  }

  mdindex& operator=(const mdindex& rhs){
    try{
      if(rhs.max_!=this->max_) 
        throw std::runtime_error("RUNTIME ERROR: DIMENSION DOES NOT MATCH!");
      current_=rhs.current_;
    }catch(std::runtime_error e){
      std::cerr << "Max size: " ;
      for(int i=0; i!=max_.size(); ++i) std::cerr << max_[i] <<"  " ;
      std::cerr << std::endl;
      throw;
    }
  }

  mdindex& operator++(){ // ++index
    try{
      for(auto i=0; i!=current_.size(); ++i){
        ++current_[i];
        if(current_[i]<max_[i]){
          ++totalindex_;
          return *this;
        }else{
          current_[i]=0;
        }
      }
      throw std::runtime_error("RUNTIME ERROR: OUT OF RANGE!");
    }catch(std::runtime_error e){
      std::cerr << "Max size: " ;
      for(int i=0; i!=max_.size(); ++i) std::cerr << max_[i] <<"  " ;
      std::cerr << std::endl;
      throw;
    }

  }

  mdindex operator++(int){ // index++
    mdindex ret=*this;
    ++(*this);
    return ret;
  }

  mdindex& operator--(){ // --index
    try{
      for(size_t i=0; i!=current_.size(); ++i){
        if(current_[i]>0){
          --current_[i];
          --totalindex_;
          return *this;
        }else{
          current_[i]=max_[i]-1;
        }
      }
      throw std::runtime_error("RUNTIME ERROR: OUT OF RANGE!");
    }catch(std::runtime_error e){
      std::cerr << "Max size: " ;
      for(size_t i=0; i!=max_.size(); ++i) std::cerr << max_[i] <<"  " ;
      std::cerr << std::endl;
      throw;
    }
  }

  mdindex operator--(int){ // index--
    mdindex ret=*this;
    --(*this);
    return ret;
  }

  mdindex operator+(const int &inc) const{
    mdindex ret=*this;
    if(inc >=0){
      for(size_t i =0; i!= inc; ++i) ++ret;
      return ret;
    }else{
      for(size_t i =0; i!= -inc; ++i) --ret;
      return ret;
    }
  }

  mdindex operator-(const int &inc) const{
    return (*this)+(-inc);
  }

  mdindex& operator+=(const int &inc) {
    if(inc >=0){
      for(size_t i =0; i!= inc; ++i) ++(*this);
      return *this;
    }else{
      for(size_t i =0; i!= -inc; ++i) --(*this);
      return *this;
    }
  }

  mdindex& operator-=(const int &inc) {
    return (*this)+=(-inc);
  }

};
#endif // MDINDEX_H
