//
//  CTColorDef.h
//  circle_iphone
//
//  Created by sujie on 16/1/18.
//  Copyright © 2016年 ctquan. All rights reserved.
//

#ifndef CTColorDef_h
#define CTColorDef_h

// 颜色设置
#define CTClearColor [UIColor clearColor]

/** 16进制颜色 */
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define CTColorMake(r,g,b,a)    [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define CTYellowColor           CTColorMake(255,168,65,1)
#define CTBlueColor              UIColorFromRGB(0x00a0ff)
#define CTRedColor              UIColorFromRGB(0xff6000)
//#define CTGrayColor             CTColorMake(104,111,124,1)
#define CTGrayColor                  UIColorFromRGB(0x333333)
#define CTUnRespondColor        CTColorMake(204,204,204,1)
#define CTDelteColor              UIColorFromRGB(0x038ae6)

#define BLUE_COLOR          [UIColor colorWithRed:117.0f/255.0f green:201.0f/255.0f blue:231.0f/255.0f alpha:1.0f]
#define GRAY_DARK_COLOR     [UIColor colorWithRed:21.0f/255.0f green:21.0f/255.0f blue:21.0f/255.0f alpha:1.0f]
#define GRAY_COLOR          [UIColor colorWithRed:118.0f/255.0f green:118.0f/255.0f blue:118.0f/255.0f alpha:1.0f]
#define GRAY_SHALLOW_COLOR  [UIColor colorWithRed:199.0f/255.0f green:199.0f/255.0f blue:199.0f/255.0f alpha:1.0f]

#define NORMAL_FONT_COLOR  CTCOLOR_BLACK_A
#define NORMAL_DETAIL_FONT_COLOR  CTCOLOR_GRAY_B
#define GRAY_FONT_COLOR UIColorFromRGB(0xbdbdbd)



/** v2.0 颜色宏定义 */

//字体颜色
#define CTCOLOR_BLACK_A                  UIColorFromRGB(0x151515)
#define CTCOLOR_BLACK_B                  UIColorFromRGB(0x1e1e1e)
/** 灰色提示小字 */
#define CTCOLOR_BLACK_C                  UIColorFromRGB(0x767676)
#define CTCOLOR_BLACK_D                  UIColorFromRGB(0xaaaaaa)

#define CTCOLOR_GRAY_A                   UIColorFromRGB(0x707c95)
#define CTCOLOR_GRAY_B                   UIColorFromRGB(0x686f7c)
#define CTCOLOR_GRAY_C                   UIColorFromRGB(0x9f9f9f)

#define CTCOLOR_BLUE_A                   UIColorFromRGB(0x038ae6)

#define CTCOLOR_RED_A                    UIColorFromRGB(0xfa2400)

#define CTCOLOR_YELLOW_A                 UIColorFromRGB(0xffa841)

#define CTCOLOR_GREEN_A                  UIColorFromRGB(0x22ac38)

#define CTCOLOR_WHITE_NORMAL             UIColorFromRGB(0xffffff)
#define CTCOLOR_WHITE_A                  UIColorFromRGB(0xf6f7f8)

//背景色
#define CTCOLOR_BACKGROUND_GRAY_A        UIColorFromRGB(0xf5f5f5)
#define CTCOLOR_LINE_COLOR   UIColorFromRGB(0xe6e6e6)

#define CTFONT_NORMAL_COLOR UIColorFromRGB(0x333333)
#define CTFONT_GLOOMY_COLOR UIColorFromRGB(0x999999)


//分隔符
#define CTCOLOR_SEPARATOR_GRAY_A         UIColorFromRGB(0xd1d4d9)
#define CTCOLOR_SEPARATOR_GRAY_B         UIColorFromRGB(0xc3c6ce)

#endif

/* CTColorDef_h */
