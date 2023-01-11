//
// Created by ramir on 26.12.2022.
//

#ifndef SEMWORK_VIEWFIELD_H
#define SEMWORK_VIEWFIELD_H

#include <cstdio>

class ViewField {
    char *field;
    int width;
    int height;
public:
    ViewField(int w,int h):width(w),height(h){
        field = new char[w*h];
        for (int i = 0; i < w*h; ++i)
            field[i]=' ';
    }
    ~ViewField(){
        delete field;
    }
    void Set(int x,int y,char c){
        if(x>=0 && x<width && y>=0 && y<height)
            field[y*width+x]=c;
    }
    char Get(int x,int y){
        if(x>=0 && x<width && y>=0 && y<height)
            return field[y*width+x];
        return ' ';
    }
    void print(){
        for (int i = 0; i < width+2; ++i)
            printf("#");
        printf("\n\r");
        for (int y = 0; y < height; ++y) {
            printf("#");
            for (int x = 0; x < width; ++x)
                printf("%c",Get(x,y));
            printf("#\n\r");
        }
        for (int i = 0; i < width+2; ++i)
            printf("#");
        printf("\n\r");

        printf("Control keys:\n\r");
        printf("q - quit\n\r");
        printf("a - move paddle left\n\r");
        printf("d - move paddle right\n\r");
        printf("space - use ball\n\r");
    }
};


#endif //SEMWORK_VIEWFIELD_H
