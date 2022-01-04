#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
std::random_device rd;
std::default_random_engine gen = std::default_random_engine(rd());
void print(std::vector<int> num){
    for(int i = 1; i <= num.size(); ++i){
        std::cout << "Number " << i << ":\t" << num[i-1] << std::endl;
    }
}
void input(std::vector<int> &num,int times){
    int temp;
    for(int i = 1; i <= times; ++i){
        std::cout << "Number " << i << ":\t";
        std::cin >> temp;
        num.push_back(temp);
    }
}
void RNG_answer_creation(std::vector<int> &number, int times){
    std::uniform_int_distribution<int> dis(0,10);
    int temp_RNG;
    temp_RNG=dis(gen);
    number.push_back(temp_RNG);
    bool finding=true;
    bool first=true;
    auto num_it=number.begin();
    auto find_number_it=find(number.begin(),number.end(),temp_RNG);
    for(int i = 0;i<times;++i){
        while(finding==true){
            if(find_number_it!=number.end() && first != true){
                temp_RNG=dis(gen);
                find_number_it=find(number.begin(),number.end(),temp_RNG);
            }
            else{
                *num_it=temp_RNG;
                finding=false;
            }
        }
        if(i!=times-1){
            temp_RNG=dis(gen);
            auto temp_it=find(number.begin(),number.end(),temp_RNG);
            if(temp_it==number.end()){
                number.push_back(temp_RNG);
                find_number_it=number.end();
            }
            else{
                number.push_back(temp_RNG);
            }
            num_it=number.end()-1;
            finding=true;
            first=false;
        }
    }
}
std::vector<int> testequals(std::vector<int> &answer,std::vector<int> &check){
    std::vector<int> correct;
    for(int i=0;i<answer.size();++i){
        if(answer[i]==check[i]){
            correct.push_back(i);
        }
    }
    return correct;
}
int main(){
    std::vector<int> number;
    std::vector<int> input_num;
    int times=3;
    RNG_answer_creation(number,times);
    //std::cout<<"Answer\n";
    //print(number);
    std::cout<<"Input\n";
    input(input_num,times);
    std::vector<int> correct=testequals(number,input_num);
    for(int i=0;i<correct.size();++i){
        std::cout<< "Number " << (correct[i])+1 << " guess correctly!\n";
        std::cout<< "The number you have guessed is " << number[i] << std::endl;
    }
    if(correct.empty()){
        std::cout<<"Every number you have guess is incorrect!\n";
    }
    return 0;
}