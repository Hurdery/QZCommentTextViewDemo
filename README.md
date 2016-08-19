# QZCommentTextViewDemo
封装类网易新闻评论新闻输入框，监听键盘改变显示高度，自带黑灰背景

用法：

step1：加到你需要的vc中
    _textView =[QZTopTextView topTextView];
    _textView.delegate = self;
    [self.view addSubview:_textView];

step2：依据你的需要激活第一响应者
     [_textView.lpTextView becomeFirstResponder];

step3：代理方法获取用户输入的文本
      - (void)sendCommen;
      
缺陷：
使用几个设置颜色字体等工具，使用需要连带一些文件和pch，即CommonTools文件中所有文件
有时间会逐步把这些文件从工程中剥离出来，减小封装体积
