#include "HelloWorldScene.h"

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

    label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

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
        left_panel_sprite = Sprite::create("right.png");
        left_panel_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        left_panel_sprite->setPosition(origin.x + 220, origin.y + 55);
        left_panel_sprite->setScale(0.5f);
        this->addChild(left_panel_sprite, 1);

        //up
        up_panel_sprite = Sprite::create("right.png");
        up_panel_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        up_panel_sprite->setPosition(origin.x + 270, origin.y + 55);
        up_panel_sprite->setScale(0.5f);
        this->addChild(up_panel_sprite, 1);

        //down
        down_panel_sprite = Sprite::create("right.png");
        down_panel_sprite->setAnchorPoint(Vec2(0.5, 0.5));
        down_panel_sprite->setPosition(origin.x + 320, origin.y + 55);
        down_panel_sprite->setScale(0.5f);
        this->addChild(down_panel_sprite, 1);


        /*------------------------Event Listener create 2 --------------------------------------*/
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool {
            /*ƒ^ƒbƒ`Žž‚Ìˆ—*/
            Point touch_point = touch->getLocation();
            Rect right_sprite_rect = right_panel_sprite->boundingBox();

            if (right_sprite_rect.containsPoint(touch_point)) {
                auto str = String::create("right");
                label->setString(str->getCString());
            }
            return true;
        };

        listener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool {
            Point touch_point = touch->getLocation();
            Rect pannel_sprite_rect = panel_sprite[0][0]->boundingBox();

            if (pannel_sprite_rect.containsPoint(touch_point)) {
                auto str = String::create("right2");
                label->setString(str->getCString());

                panel_sprite[0][0]->removeFromParentAndCleanup(true);
                panel_sprite[0][0] = Sprite::create("right.png");
                panel_sprite[0][0]->setAnchorPoint(Vec2(0.5, 0.5));
                panel_sprite[0][0]->setPosition(origin.x + 170, origin.y + 100);
                panel_sprite[0][0]->setScale(0.5f);
                this->addChild(panel_sprite[0][0], 1);

            }
            return true;
        };
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
        /*------------------------Event Listener end --------------------------------------*/







        return true;
    }


    void HelloWorld::menuCloseCallback(Ref* pSender)
    {
        Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
