//
// Created by semen on 26.02.2020.
//

#ifndef LAB_ALBUM_H
#define LAB_ALBUM_H

#include <string>
#include <deque>
#include <iostream>
#include <utility>

class Data{
    private:
        std::string title;
        std::string name;
        uint32_t count;
        uint32_t year;
    public:
    Data(){

    }
    ~Data(){

    }
    Data(std::string title,std::string name,uint32_t count,uint32_t year){
        this->title =std::move(title);
        this->name =std::move(name);
        this->count =count;
        this->year =year;
    }
     void print(){
         std::cout << "Aльбом:"+ this->title + "\n";
         std::cout << "Имя исполнителя:"+ this->name + "\n";
         std::cout << "Кол-во песен:"+ std::to_string(this->count) + "\n";
         std::cout << "Год выпуска:"+ std::to_string(this->year) + "\n";
     }
     bool check_title(std::string title){
         return  this->title == title;
    }
    bool check_name(std::string name){
        return  this->name == name;
    }
};

class Album {
    private:
        std::deque<Data> list;
    Album(){

    }
    ~Album(){
        this->list.clear();
    }
    void add(std::string title,std::string name,uint32_t count,uint32_t year){
        Data data = Data(title,name,count,year);
        this->list.push_front(data);
    }
    void remove_front(){
        this->list.pop_front();
    }
    void remove_back(){
        this->list.pop_back();
    }
    void remove_for_pos(int pos){
        this->list.erase(this->list.begin() + pos);
    }
    Data find_by_title(std::string title){
        for(Data data:this->list){
            if (data.check_title(title)){
                return data;
            }
        }
    }
    std::deque<Data> filter_by_name(std::string name){
        std::deque<Data> data;
        for(Data _data:this->list){
            if (_data.check_name(name)){
                 data.push_front(_data);
            }
        }
        return data;
    }
};


#endif //LAB_ALBUM_H
