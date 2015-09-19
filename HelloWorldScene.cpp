#include "HelloWorldScene.h"
#define PRIGHT 111
#define PLEFT 112
#define PUP 113
#define PDOWN 114


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
        origin.y + closeItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /*label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);*/

    /*top create*/
    back_sprite = Sprite::create("bg3.png");
    back_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    back_sprite->setPosition(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2);
    back_sprite->setScale(0.5f);
    this->addChild(back_sprite, 0);

    /*top create*/
    top_sprite = Sprite::create("top.png");
    top_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    top_sprite->setPosition(origin.x + 250, origin.y + 250);
    top_sprite->setScale(0.5f);
    this->addChild(top_sprite, 0);

    /*bottom create*/
    bottom_sprite = Sprite::create("bottom.png");
    bottom_sprite->setAnchorPoint(Vec2(0.5, 0.5));
    bottom_sprite->setPosition(origin.x + 250, origin.y + 20);
    bottom_sprite->setScale(0.5f);
    this->addChild(bottom_sprite, 0);

    // field create"
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            panel_sprite[i][j] = Sprite::create("field.png");
            panel_sprite[i][j]->setAnchorPoint(Vec2(0.5, 0.5));
            panel_sprite[i][j]->setPosition(origin.x + 170 + i * 30, origin.y + 100 + j * 30);
            panel_sprite[i][j]->setScale(0.5f);
            this->addChild(panel_sprite[i][j], 1);
        }
    }

        //panel create
        //right
        right_panel_sprite = Sprite::create("right.png");
        right_panel_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        right_panel_sprite->setPosition(origin.x + 170, origin.y + 55);
        right_panel_sprite->setScale(0.5f);
        this->addChild(right_panel_sprite, 1);


        //left
        left_panel_sprite = Sprite::create("left.png");
        left_panel_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        left_panel_sprite->setPosition(origin.x + 220, origin.y + 55);
        left_panel_sprite->setScale(0.5f);
        this->addChild(left_panel_sprite, 1);

        //up
        up_panel_sprite = Sprite::create("up.png");
        up_panel_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        up_panel_sprite->setPosition(origin.x + 270, origin.y + 55);
        up_panel_sprite->setScale(0.5f);
        this->addChild(up_panel_sprite, 1);

        //down
        down_panel_sprite = Sprite::create("down.png");
        down_panel_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        down_panel_sprite->setPosition(origin.x + 320, origin.y + 55);
        down_panel_sprite->setScale(0.5f);
        this->addChild(down_panel_sprite, 1);


        /*------------------------Event Listener create 2 --------------------------------------*/
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool {
            /*?^?b?`????????*/
            Point touch_point = touch->getLocation();
            Rect right_sprite_rect = right_panel_sprite->boundingBox();
            Rect left_sprite_rect = left_panel_sprite->boundingBox();
            Rect up_sprite_rect = up_panel_sprite->boundingBox();
            Rect down_sprite_rect = down_panel_sprite->boundingBox();

            if (right_sprite_rect.containsPoint(touch_point)) {
                auto str = String::create("right");
                label->setString(str->getCString());
                way = PRIGHT;
            }
            else if (left_sprite_rect.containsPoint(touch_point)) {
                auto str = String::create("left");
                label->setString(str->getCString());
                way = PLEFT;
            }
            else if (up_sprite_rect.containsPoint(touch_point)) {
                auto str = String::create("up");
                label->setString(str->getCString());
                way = PUP;
            }
            else if (down_sprite_rect.containsPoint(touch_point)) {
                auto str = String::create("down");
                label->setString(str->getCString());
                way = PDOWN;
            }
            return true;
        };

        listener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool {
            Point touch_point = touch->getLocation();

            //Rect pannel_sprite_rect = panel_sprite[0][0]->boundingBox();
            Rect pannel_sprite_rect[6][6];
            
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    pannel_sprite_rect[i][j] = panel_sprite[i][j]->boundingBox();
                }
            }
            
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (pannel_sprite_rect[i][j].containsPoint(touch_point)) {
                        auto str = String::create("right2");
                        label->setString(str->getCString());

                        panel_sprite[i][j]->removeFromParentAndCleanup(true);

                        if (way == PRIGHT) {
                            panel_sprite[i][j] = Sprite::create("right.png");

                        }
                        else if (way == PLEFT) {
                            panel_sprite[i][j] = Sprite::create("left.png");

                        }
                        else if (way == PUP) {
                            panel_sprite[i][j] = Sprite::create("up.png");

                        }
                        else if (way == PDOWN) {
                            panel_sprite[i][j] = Sprite::create("down.png");

                        }

                        panel_sprite[i][j]->setAnchorPoint(Vec2(0.5, 0.5));
                        panel_sprite[i][j]->setPosition(origin.x + 170 + i * 30, origin.y + 100 + j * 30);
                        panel_sprite[i][j]->setScale(0.5f);
                        this->addChild(panel_sprite[i][j], 1);
                    }
                }
            }

            return true;
        };
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
        /*------------------------Event Listener end --------------------------------------*/


        /*soldeir*/
        soldier_sprite = Sprite::create("soldier.png");
        soldier_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        soldier_sprite->setPosition(origin.x + 170, origin.y + 100);
        soldier_sprite->setScale(0.02f);
        auto UP = MoveBy::create(time, Vec2(0, move_l));
        auto DOWN = MoveBy::create(time, Vec2(0, -move_l));
        auto RIGHT = MoveBy::create(time, Vec2(move_l, 0));
        auto LEFT = MoveBy::create(time, Vec2(-move_l, 0));
        this->addChild(soldier_sprite, 1);
        soldier_sprite->runAction(Sequence::create(
            RIGHT,
            UP,
            UP,
            RIGHT,
            DOWN,
            RIGHT,
            DOWN,
            RIGHT,
            UP,
            UP,
            LEFT,
            UP,
            LEFT,
            UP,
            RIGHT,
            UP,
            RIGHT,
            DOWN,
            DOWN,
            RIGHT,
            UP,
            UP,
            NULL
            ));
        

        return true;
    }


    void HelloWorld::menuCloseCallback(Ref* pSender)
    {
        Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
