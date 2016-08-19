//
//  UIFont+UIFont+Extension.h
//  circle_iphone
//
//  Created by trandy on 15/11/23.
//  Copyright © 2015年 ctquan. All rights reserved.
//

#import "UIFont+Extension.h"

@implementation UIFont (Extension)

+ (UIFont *)ctBoldFontOfSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        return [UIFont fontWithName:@"PingFangSC-Semibold" size:fontSize];
    }else
    {
        return [UIFont boldSystemFontOfSize:fontSize];
    }
}

+ (UIFont *)ctBoldFontOfAutoSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        //        return [UIFont fontWithName:@"PingFangSC-Semibold" size:fontSize];
        return [UIFont fontWithName:@"PingFangSC-Semibold" size:[UIFont convertFontSize:fontSize]];
    }else
    {
        //        return [UIFont boldSystemFontOfSize:fontSize];
        return [UIFont boldSystemFontOfSize:[UIFont convertFontSize:fontSize]];
    }
}

+ (UIFont *)ctRegularFontOfSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        return [UIFont fontWithName:@"PingFangSC-Regular" size:fontSize];
    }else
    {
        return [UIFont systemFontOfSize:fontSize];
    }
}

+ (UIFont *)ctRegularFontOfAutoSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        //        return [UIFont fontWithName:@"PingFangSC-Regular" size:fontSize];
        return [UIFont fontWithName:@"PingFangSC-Regular" size:[UIFont convertFontSize:fontSize]];
    }else
    {
        //        return [UIFont boldSystemFontOfSize:fontSize];
        return [UIFont systemFontOfSize:[UIFont convertFontSize:fontSize]];
    }
}

+ (UIFont *)ctAZRegularFontOfSize:(CGFloat)fontSize
{
    if (IS_IPHONE6P) {
        fontSize=fontSize*1.1;
    }
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        return [UIFont fontWithName:@"PingFangSC-Regular" size:fontSize];
//        return [UIFont fontWithName:@"PingFangSC-Regular" size:[UIFont convertFontSize:fontSize]];
    }else
    {
        return [UIFont systemFontOfSize:fontSize];
//        return [UIFont systemFontOfSize:[UIFont convertFontSize:fontSize]];
    }
}

+ (UIFont *)ctMediumFontOfSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        return [UIFont fontWithName:@"PingFangSC-Medium" size:fontSize];
//        return [UIFont fontWithName:@"PingFangSC-Medium" size:[UIFont convertFontSize:fontSize]];
    }else
    {
        return [UIFont boldSystemFontOfSize:fontSize];
//        return [UIFont boldSystemFontOfSize:[UIFont convertFontSize:fontSize]];
    }
}

+ (UIFont *)ctLightFontOfSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        return [UIFont fontWithName:@"PingFangSC-Light" size:fontSize];
//        return [UIFont fontWithName:@"PingFangSC-Light" size:[UIFont convertFontSize:fontSize]];
    }else
    {
        return [UIFont boldSystemFontOfSize:fontSize];
//        return [UIFont boldSystemFontOfSize:[UIFont convertFontSize:fontSize]];
    }
}

+ (UIFont *)ctThinFontOfSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        return [UIFont fontWithName:@"PingFangSC-Thin" size:fontSize];
//        return [UIFont fontWithName:@"PingFangSC-Thin" size:[UIFont convertFontSize:fontSize]];
    }else
    {
        return [UIFont boldSystemFontOfSize:fontSize];
//        return [UIFont boldSystemFontOfSize:[UIFont convertFontSize:fontSize]];
    }
}

+ (UIFont *)ctULTRALIGHTFontOfSize:(CGFloat)fontSize
{
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) {
        return [UIFont fontWithName:@"PingFangSC-Ultralight" size:fontSize];
//        return [UIFont fontWithName:@"PingFangSC-Ultralight" size:[UIFont convertFontSize:fontSize]];
    }else
    {
        return [UIFont boldSystemFontOfSize:fontSize];
//        return [UIFont boldSystemFontOfSize:[UIFont convertFontSize:fontSize]];
    }
}

+ (NSInteger)convertFontSize:(NSInteger)fontSize
{
    //10-2   10.5
//    id fontS;
//    fontS  NSNumber  NSString  NSScanner
    
    NSInteger size = 0;
    
    NSString* plistPath = [[NSBundle mainBundle] pathForResource:@"ConverFontSize" ofType:@"plist"];
    NSDictionary *allDic = [[NSDictionary alloc] initWithContentsOfFile:plistPath];
    
    NSDictionary *tempDic = allDic[[NSString stringWithFormat:@"%ld",(long)fontSize]];
    if (IS_IPHONE5) {
        size = [tempDic[@"iphone5"] integerValue];
    }else if (IS_IPHONE6) {
        size = [tempDic[@"iphone6"] integerValue];
    }else if (IS_IPHONE6P)
    {
        size = [tempDic[@"iphone6p"] integerValue];
    }else
    {
        // ipad 设备 使用 6 字体
        size = [tempDic[@"iphone6"] integerValue];
    }
    
    NSString *str=[NSString stringWithFormat:@"对照表内没有对应字号:%.1ld",(long)fontSize];
    NSAssert(size != 0, str);
    
    return size;
}

@end
