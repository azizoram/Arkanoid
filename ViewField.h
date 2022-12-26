//
// Created by ramir on 26.12.2022.
//

#ifndef SEMWORK_VIEWFIELD_H
#define SEMWORK_VIEWFIELD_H


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
};


#endif //SEMWORK_VIEWFIELD_H
