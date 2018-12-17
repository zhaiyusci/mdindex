#include"mdindex.h"
#include<iostream>

int main(){
  std::vector<int> max{2,3,4};
  mdindex in(max);
  /*
     mdindex inn;
     inn=in;
     std::cout << "Assignment:   " 
     << inn.current()[0] <<"   "
     << inn.current()[1] <<"   "
     << inn.current()[2] << std::endl;
     */


  std::cout << "increment operator" << std::endl;
  for(int i=0; i!=23; ++i){
    std::cout << i  << ":   " 
      << in.current()[0] <<"   "
      << in.current()[1] <<"   "
      << in.current()[2] << std::endl;
    // std::cout << __FILE__ << "  " << __LINE__ << std::endl;
    ++in;
  }
  std::cout << "increment operator" << std::endl;
  for(int i=0; i!=23; ++i){
    std::cout << in.totalindex() << ":   " 
      << in.current()[0] <<"   "
      << in.current()[1] <<"   "
      << in.current()[2] << std::endl;
    // std::cout << __FILE__ << "  " << __LINE__ << std::endl;
    --in;
  }

  std::cout <<"+= -="<<std::endl;
  std::cout <<"current"<<std::endl;
  std::cout  << ":   " 
    << in.current()[0] <<"   "
    << in.current()[1] <<"   "
    << in.current()[2] << std::endl;
  in+=3;

  std::cout  << ":   " 
    << in.current()[0] <<"   "
    << in.current()[1] <<"   "
    << in.current()[2] << std::endl;
  in-=3;
  std::cout  << ":   " 
    << in.current()[0] <<"   "
    << in.current()[1] <<"   "
    << in.current()[2] << std::endl;

  in+=5;
  mdindex inn(in);
  std::cout  << ":   " 
    << inn.current()[0] <<"   "
    << inn.current()[1] <<"   "
    << inn.current()[2] << std::endl;




  return 0;
}
