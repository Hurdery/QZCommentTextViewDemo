//
//  UIFont+Extension.h
//  circle_iphone
//
//  Created by trandy on 15/11/23.
//  Copyright © 2015年 ctquan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIFont (Extension)

+ (UIFont *)ctBoldFontOfSize:(CGFloat)fontSize;
+ (UIFont *)ctBoldFontOfAutoSize:(CGFloat)fontSize;

+ (UIFont *)ctRegularFontOfSize:(CGFloat)fontSize;
+ (UIFont *)ctRegularFontOfAutoSize:(CGFloat)fontSize;

+ (UIFont *)ctAZRegularFontOfSize:(CGFloat)fontSize;
+ (UIFont *)ctMediumFontOfSize:(CGFloat)fontSize;
+ (UIFont *)ctLightFontOfSize:(CGFloat)fontSize;
+ (UIFont *)ctThinFontOfSize:(CGFloat)fontSize;
+ (UIFont *)ctULTRALIGHTFontOfSize:(CGFloat)fontSize;

/** 字号转换，传入字号为iphone5标准 */
+ (NSInteger)convertFontSize:(NSInteger)fontSize;

@end
