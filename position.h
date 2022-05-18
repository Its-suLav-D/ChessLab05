#pragma once
#include <iostream>
#include <string>
class Position
{
private:
    double squareWidth;
    double squareHeight;
    int location;
public:
    // constructors
    Position(): location(-1){};
    
    Position(int loc): location(loc){};
    Position(int r, int c): location(0) {   set(r,c);   }
    // Operator Defined
    Position(const char * c): location(0) { *this = c;}
    // Copy Constructor
    Position(const Position & rhs):location(rhs.location),squareWidth(rhs.squareWidth), squareHeight(rhs.squareHeight){};
    
    
    // getters
    int getLocation();
    int getRow();
    int getCol();
    int getX();
    int getY();
    
    double getSquareWidth() const {return squareWidth;}
    double getSquareHeight() const {return squareHeight;}
    
    bool isInvalid() const {return location < 0 || location >=64;}
    bool isValid() const {return !isInvalid();}
    
    // setters
    void setRow(int row);
    void setCol(int col);
    void set(int row, int col);
    
    
    void adjustRow(int dRow);
    void adjustCol(int dCol);
    
    void setSquareWidth(double width) {if(width > 0.0) squareWidth = width;}
    
    
    void setSquareHeight(double height) {if(height > 0.0) squareHeight = height;}

    
    // Assignment Operator Overloaded
    const Position &operator = (const Position &rhs)
    {
        location = rhs.location;
        squareWidth = rhs.squareWidth;
        squareHeight = rhs.squareHeight;
        return *this;
    }
    
    Position & operator = (Position && rhs)
    {
        
        return *this;
    }
    
//    Position & operator = (const char *rhs)
//    {
//        location = rhs;
//        int col = location[0]-'a';
//        int row = location[1]-'1';
//        int position = row *8 +col;
//        locationInt = position;
//        return *this;
//    }
    
    Position & operator = (const std::string &rhs)
    {
        int col = rhs[0]-'a';
        int row = rhs[1]-'1';
        int position = row *8 +col;
        location = position;
        return *this;
    }
    
    const Position &operator = (const char * rhs);
    

    
    
    
    
    bool operator < (const Position &rhs) const {return location < rhs.location;}
    
    bool operator == (const Position &rhs)const;
    
    bool operator != (const Position &rhs) const;
    

    
//    bool operator == (const Position & rhs)const
//    {
//        return location == rhs.location;
//    }
   
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in, Position& pt);
