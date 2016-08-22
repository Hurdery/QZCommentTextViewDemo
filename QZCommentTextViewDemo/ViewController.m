//
//  ViewController.m
//  QZCommentTextViewDemo
//
//  Created by MrYu on 16/8/20.
//  Copyright © 2016年 yu qingzhu. All rights reserved.
//

#import "ViewController.h"
#import "QZTopTextView.h"


@interface ViewController ()<QZTopTextViewDelegate>
{
    QZTopTextView * _textView;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *btn = [[UIButton alloc] init];
    btn.frame = CGRectMake(100, 100, 150, 30);
    btn.center = CGPointMake(self.view.center.x,btn.center.x);
    [btn setTitle:@"评论" forState:UIControlStateNormal];
    btn.backgroundColor = [UIColor lightGrayColor];
    [btn addTarget:self action:@selector(write) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
    
    
    
    _textView =[QZTopTextView topTextView];
    _textView.delegate = self;
    [self.view addSubview:_textView];
}

- (void)write
{
    [_textView.lpTextView becomeFirstResponder];
}

- (void)sendComment
{
    NSLog(@"%@",_textView.lpTextView.text);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end
