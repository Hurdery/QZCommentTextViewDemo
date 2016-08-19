//
//  CommonDef.h
//  circle_iphone
//
//  Created by trandy on 15/3/2.
//  Copyright (c) 2015年 ctquan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum _GenderType
{
    Gender_Unknow = 0,      //unknow
    Gender_Male = 1,        //man
    Gender_Female = 2,      //woman
}GenderType;

typedef enum _ActionType
{
    Action_New      = 0,        //new
    Action_Update   = 1,        //update
    Action_Delete   = 2,        //delete
}ActionType;

typedef enum _LogOwner
{
    Log_All     =0,
    Log_LW      =1,
    Log_SYX     =2,
    Log_Andrew  =3,
    Log_FWB    =4,
    Log_YQZ =5,
}LogOwner;


// 暂时 注销 pingpp
//#define MAC_PRO_ADDRES @"ANDREW_PRO"

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


// NSLog((@"[文件名:%s]" "[函数名:%s]" "[行号:%d]" format), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);  

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



/** 邀请点评项目 点评内容（投资人点评创业者项目） */

#define AZ_COMMENT_INVITE_PROJECT @"az_comment_invite_project_"

#define AZ_COMMENT_INVITE_PROJECT_KEY(orderid) [NSString stringWithFormat:@"%@%ld",AZ_COMMENT_INVITE_PROJECT,orderid]

#define IS_HAVE_COMMENT_INVITE_PROJECT(orderid)   [[NSUserDefaults standardUserDefaults] objectForKey:AZ_COMMENT_INVITE_PROJECT_KEY(orderid)]

#define DELETE_COMMENT_INVITE_PROJECT(orderid)   [[NSUserDefaults standardUserDefaults] removeObjectForKey:AZ_COMMENT_INVITE_PROJECT_KEY(orderid)]

#define SAVE_COMMENT_INVITE_PROJECT(orderid,content)  [[NSUserDefaults standardUserDefaults] setObject:content forKey:AZ_COMMENT_INVITE_PROJECT_KEY(orderid)]

#define AZ_COMMENT_INVITE_PROJECT_CONTENT(orderid)  IS_HAVE_COMMENT_INVITE_PROJECT(orderid)

/** 点评推送是否已读 */
#define IS_READ_PUSH_OPTION @"is_read_push_option"



/** 邀请订单序号 */
#define INVITE_ORDER_ROWINDEX @"invite_order_rowindex"

/** 保存邀请订单序号 */
#define REMMER_INVITE_ORDER_ROWINDEX(ROW)  [[NSUserDefaults standardUserDefaults] setObject:[NSNumber numberWithInteger:ROW] forKey:INVITE_ORDER_ROWINDEX];[[NSUserDefaults standardUserDefaults] synchronize]

/** 获取邀请订单序号 值为integerValue */
#define REMMER_INVITE_ORDER_ROWINDEX_VALUE  [[[NSUserDefaults standardUserDefaults] objectForKey:INVITE_ORDER_ROWINDEX] integerValue]


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
//#define CTFONT_MEDIUM(f)             CTFONT_REGULAR(f)
//#define CTFONT_LIGHT(f)              CTFONT_REGULAR(f)
//#define CTFONT_THIN(f)               CTFONT_REGULAR(f)
//#define CTFONT_ULTRALIGHT(f)         CTFONT_REGULAR(f)
//
//
//#endif


// 基本设置位置函数
#define CTPoint(x,y)        CGPointMake((x),(y))
#define CTSize(w,h)         CGSizeMake((w),(h))
#define CTRect(x,y,w,h)     CGRectMake((x),(y),(w),(h))
#define CTRectOff(r,x,y)    CGRectOffset((r), (x), (y))

//navBar左右按钮距离边框长度
#define LEFT_BTN_X_5        @0
#define LEFT_BTN_X_6        @0
#define LEFT_BTN_X_6P       @0
#define RIGHT_BTN_X_5       @5
#define RIGHT_BTN_X_6       @5
#define RIGHT_BTN_X_6P      @5

//Label行间距
#define LABEL_LINE_SPACE_5  @(10/2.0f)
#define LABEL_LINE_SPACE_6  @(10/2.0f)
#define LABEL_LINE_SPACE_6P @(20/3.0f)

// 设备高度
#define DEVICE_HEIGHT   ([[UIScreen mainScreen] bounds].size.height)
// 设备宽度
#define DEVICE_WIDTH    ([[UIScreen mainScreen] bounds].size.width)
// 设备Rect
#define DEVICE_RECT     CGRectMake(0,0,DEVICE_WIDTH,DEVICE_HEIGHT)

#define SCREEN_HEIGHT  DEVICE_HEIGHT
#define SCREEN_WIDTH   DEVICE_WIDTH

// navigationbar 顶部高度
#define CT_BASE_NAV_HEIGHT 0


/** 聊天界面下方增加高度 */
#define AZBPVIEW_BOTTOM_EXT_HEIGHT 50

/** 限制约见地址 输入24个字 */
#define LIMIT_MEET_ADDR_LENTH 24

// 编码对照表
#define SUCCEED     10000       //成功
#define APPLY_BP_HAS_EXIST  10017  //存在申请bp
#define WX_PAY_MONEY_REDPACK_SUCCESS 30002  // 微信红包支付成功
#define WX_PAY_MONEY_REWARD_SUCCESS  40000  // 私信打赏支付成功
#define NO_NETWORK_CODE  10005  // 没有网络错误码


// launchImage 缓存
#define CTQ_LAUNCHIMAGE @"CTQ_LAUNCHIMAGE_AZCDASD@#1~^SFS"




#define RemovePerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)



