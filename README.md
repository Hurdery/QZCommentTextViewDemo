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
      
发布判断文本非空功能在外部编写的话移除issueBtnClicked方法中放弃第一响应者操作，否则文本为空也会使View直接消失
