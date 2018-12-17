#ifndef MDINDEX_H
#define MDINDEX_H
#include<vector>
#include<iostream>
class mdindex{
  const std::vector <int> max_; 
  // max number of each dimension, staring from 0
  std::vector <int> current_; 
  // current indices
  int totalindex_;
  public:
  mdindex(const std::vector <int> &max): 
    max_(max), current_(max.size(),0), totalindex_(0){ 
    }
  mdindex(const mdindex& rhs):max_(rhs.max()), 
  current_(rhs.max().size(),0), totalindex_(0){
  }

  const std::vector<int> & current() const{
    return current_;
  }
  const std::vector<int> & max()const {
    return max_;
  }
  const int & totalindex()const {
    return totalindex_;
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
      for(auto i=0; i!=current_.size(); ++i){
        --current_[i];
        if(current_[i]>=0){
          --totalindex_;
          return *this;
        }else{
          current_[i]=max_[i]-1;
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

  mdindex operator--(int){ // index--
    mdindex ret=*this;
    --(*this);
    return ret;
  }

  mdindex operator+(const int &inc) const{
    mdindex ret=*this;
    if(inc >=0){
      for(int i =0; i!= inc; ++i) ++ret;
      return ret;
    }else{
      for(int i =0; i!= -inc; ++i) --ret;
      return ret;
    }
  }

  mdindex operator-(const int &inc) const{
    mdindex ret=*this;
    if(inc >=0){
      for(int i =0; i!= inc; ++i) --ret;
      return ret;
    }else{
      for(int i =0; i!= -inc; ++i) ++ret;
      return ret;
    }
  }

  mdindex& operator+=(const int &inc) {
    if(inc >=0){
      for(int i =0; i!= inc; ++i) ++(*this);
      return *this;
    }else{
      for(int i =0; i!= -inc; ++i) --(*this);
      return *this;
    }
  }

  mdindex& operator-=(const int &inc) {
    if(inc >=0){
      for(int i =0; i!= inc; ++i) --(*this);
      return *this;
    }else{
      for(int i =0; i!= -inc; ++i) ++(*this);
      return *this;
    }
  }

};
#endif // MDINDEX_H
