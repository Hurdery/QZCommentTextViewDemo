//
//  CommonDef.h
//  circle_iphone
//
//  Created by trandy on 15/3/2.
//  Copyright (c) 2015年 ctquan. All rights reserved.
//

#import <Foundation/Foundation.h>

// 暂时 注销 pingpp

#define VERSION     [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define CTSYS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

#ifdef TEST_ENV_PRODUCTION

#define CTLogBase(owner,onwer_type,fmt,...)

#elif defined TEST_ENV_QA


#define CTLogBase(owner,onwer_type,fmt,...) if ([[CTLog defaultCTLog].owners containsObject:[NSNumber numberWithInteger:Log_All]] || [[CTLog defaultCTLog].owners containsObject:[NSNumber numberWithInteger:onwer_type]])\
{\
    NSLog((@"%s [owner: %@] [line: %d] \n--------\n" fmt "\n--------\n"),__FUNCTION__, owner,__LINE__, ##__VA_ARGS__);\
}\


#endif



#define LWLog(fmt,...) CTLogBase(@"LW",Log_LW,fmt,##__VA_ARGS__)
#define SYXLog(fmt,...) CTLogBase(@"SYX",Log_SYX,fmt,##__VA_ARGS__)
#define AZLog(fmt,...) CTLogBase(@"Andrew",Log_Andrew,fmt,##__VA_ARGS__)
#define FWBLog(fmt,...) CTLogBase(@"FWB",Log_FWB,fmt,##__VA_ARGS__)
#define QZLog(fmt,...) CTLogBase(@"YQZ",Log_YQZ,fmt,##__VA_ARGS__)


#ifdef TEST_ENV_PRODUCTION

#define CTLogFunction

#elif defined TEST_ENV_QA

#define CTLogFunction NSLog(@"CTLogFunction:%s,Line:%d", __FUNCTION__,__LINE__)

#endif



/** 边框 圆角 */
#define CT_CORNER_RADIES  8.0
#define LINE_BORDER_COLOR UIColorFromRGB(0xe6e6e6)

// 手机操作系统版本
#define DEVICE_OS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

// 基本设备类型判断(竖版) iphone／itouch   ipad
#define IS_IPHONEUI   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPADUI     (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE4     ((int)DEVICE_HEIGHT%480==0)
#define IS_IPHONE5     ((int)DEVICE_HEIGHT%568==0)
#define IS_IPAD        ((int)DEVICE_HEIGHT%1024==0)
#define IS_IPHONE6      ((int)DEVICE_HEIGHT%667==0)
#define IS_IPHONE6P     ((int)DEVICE_HEIGHT%736==0)

#define CT_SCALE        DEVICE_HEIGHT/568.0
#define CT_SCALE_X      DEVICE_WIDTH/320.0
#define CT_SCALE_Y      DEVICE_HEIGHT/568.0


// 5  6  比例一致，6p 放大
#define CT6_SCALE_X      (IS_IPHONE6P?CT_SCALE_X:1)
#define CT6_SCALE_Y      (IS_IPHONE6P?CT_SCALE_Y:1)



#define CONVERT_SCALE(x) (x)/2

// 标注图按照 6 的尺寸标注 使用下面的自动转化

/** width 转化为最低兼容设备尺寸 */
#define ConvertTo6_W(x) (CONVERT_SCALE(x)*320)/375

/** height 转化为最低兼容设备尺寸 */
#define ConvertTo6_H(x) (CONVERT_SCALE(x)*568)/667



#define CTRectSmall(x,y,w,h) CGRectMake((x)/CT_SCALE_X,(y)/CT_SCALE_Y,(w)/CT_SCALE_X,(h)/CT_SCALE_Y)
#define CTRectXYXY(x,y,w,h) CGRectMake((x)*CT_SCALE_X,(y)*CT_SCALE_Y,(w)*CT_SCALE_X,(h)*CT_SCALE_Y)
#define CTRect__XY(x,y,w,h) CGRectMake((x),(y),(w*CT_SCALE_X),(h*CT_SCALE_Y))
#define CTRectXY__(x,y,w,h) CGRectMake((x)*CT_SCALE_X,(y)*CT_SCALE_Y,(w),(h))
#define CTRectXYX_(x,y,w,h) CGRectMake((x)*CT_SCALE_X,(y)*CT_SCALE_Y,(w)*CT_SCALE_X,(h))
#define CTRectX_X_(x,y,w,h) CGRectMake((x)*CT_SCALE_X,(y),(w)*CT_SCALE_X,(h))
#define CTRectX_XY(x,y,w,h) CGRectMake((x)*CT_SCALE_X,(y),(w)*CT_SCALE_X,(h)*CT_SCALE_Y)
#define CTRect_Y_Y(x,y,w,h) CGRectMake((x),(y)*CT_SCALE_Y,(w),(h)*CT_SCALE_Y)
#define CTRect_YXY(x,y,w,h) CGRectMake((x),(y)*CT_SCALE_Y,(w)*CT_SCALE_X,(h)*CT_SCALE_Y)



//// 字体字号
#define CTFONT_BOLD(f)               [UIFont boldSystemFontOfSize:(f)]
#define CTFONT_AUTO_BOLD(f)        [UIFont ctBoldFontOfAutoSize:f]
#define CTFONT_REGULAR(f)            [UIFont ctRegularFontOfAutoSize:f]


// 基本设置位置函数
#define CTPoint(x,y)        CGPointMake((x),(y))
#define CTSize(w,h)         CGSizeMake((w),(h))
#define CTRect(x,y,w,h)     CGRectMake((x),(y),(w),(h))
#define CTRectOff(r,x,y)    CGRectOffset((r), (x), (y))

// 设备高度
#define DEVICE_HEIGHT   ([[UIScreen mainScreen] bounds].size.height)
// 设备宽度
#define DEVICE_WIDTH    ([[UIScreen mainScreen] bounds].size.width)
// 设备Rect
#define DEVICE_RECT     CGRectMake(0,0,DEVICE_WIDTH,DEVICE_HEIGHT)

#define SCREEN_HEIGHT  DEVICE_HEIGHT
#define SCREEN_WIDTH   DEVICE_WIDTH







