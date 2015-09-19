#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
private:
    cocos2d::Sprite* field_sprite;
    cocos2d::Sprite* top_sprite;
    cocos2d::Sprite* bottom_sprite;
    cocos2d::Sprite* left_panel_sprite;
    cocos2d::Sprite* right_panel_sprite;
    cocos2d::Sprite* up_panel_sprite;
    cocos2d::Sprite* down_panel_sprite;
    cocos2d::Sprite* demon_sprite;
    cocos2d::Sprite* soldier_sprite;
    cocos2d::Sprite* panel_sprite[6][6];
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Label* label;
    int way;
    int time = 1;
    int move_l = 30;

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
