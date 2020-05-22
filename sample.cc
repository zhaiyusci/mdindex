#include"mdindex.h"
#include<iostream>

int main(){
  std::vector<int> max{2,3,4};
  mdindex in(max);

  std::cout << "increment operator" << std::endl;
  for(mdindex i({2,3,5}); i; ++i){
    std::cout << (int)i  << ":   " 
      << i.get(0) <<"   "
      << i.get(1) <<"   "
      << i.get(2) << std::endl;
    // std::cout << __FILE__ << "  " << __LINE__ << std::endl;
  }

  in += 12;
    std::cout << (int)in  << ":   " 
      << in.get(0) <<"   "
      << in.get(1) <<"   "
      << in.get(2) << std::endl;
  

  return 0;

  std::cout << "increment operator" << std::endl;
  for(int i=0; i!=23; ++i){
    std::cout << in.get() << ":   " 
      << in.get(0) <<"   "
      << in.get(1) <<"   "
      << in.get(2) << std::endl;
    // std::cout << __FILE__ << "  " << __LINE__ << std::endl;
    --in;
  }

  std::cout <<"+= -="<<std::endl;
  std::cout <<"get"<<std::endl;
  std::cout  << ":   " 
    << in.get(0) <<"   "
    << in.get(1) <<"   "
    << in.get(2) << std::endl;
  in+=3;

  std::cout  << ":   " 
    << in.get(0) <<"   "
    << in.get(1) <<"   "
    << in.get(2) << std::endl;
  in-=3;
  std::cout  << ":   " 
    << in.get(0) <<"   "
    << in.get(1) <<"   "
    << in.get(2) << std::endl;

  unsigned int inccc=3;
  in+=inccc;
  mdindex inn(in);
  std::cout  << "copied:   " 
    << inn.get(0) <<"   "
    << inn.get(1) <<"   "
    << inn.get(2) << std::endl;
  inn.reset();
  std::cout  << "reseted:   " 
    << inn.get(0) <<"   "
    << inn.get(1) <<"   "
    << inn.get(2) << std::endl;


  inn.reset();
  inn+=5;
  std::cout  << "+= 5:   " 
    << inn.get(0) <<"   "
    << inn.get(1) <<"   "
    << inn.get(2) << std::endl;
  inn-=-5;
  std::cout  << "-=-5:   " 
    << inn.get(0) <<"   "
    << inn.get(1) <<"   "
    << inn.get(2) << std::endl;
  inn+=-5;
  std::cout  << "+=-5:   " 
    << inn.get(0) <<"   "
    << inn.get(1) <<"   "
    << inn.get(2) << std::endl;
  inn-=5;
  std::cout  << "-= 5:   " 
    << inn.get(0) <<"   "
    << inn.get(1) <<"   "
    << inn.get(2) << std::endl;


  return 0;
}
