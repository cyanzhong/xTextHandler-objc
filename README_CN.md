# Let's Swift!
xTextHandler 已经完全使用 Swift 重写，你可以在这里找到 Swift 版本：https://github.com/cyanzhong/xTextHandler

⚠️Objective-C 版本将不再维护

# xTextHandler
Xcode Source Editor 插件集

# 这是什么
基于 [Xcode Source Editor Extension](https://developer.apple.com/videos/play/wwdc2016/414/) 的插件集，提高 Xcode 文本处理的体验，你可以通过简单的几行代码扩展它

# 特点
- 支持文本多行选择
- 支持多个类型的插件
- 提供易扩展的接口
- 支持剪贴板文本（当没有选择文本，处理剪贴板文本）
- 提供基于正则表达式的匹配

## xEncode
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler/master/GIFs/xEncode.gif)
- Base64 Encode
- Base64 Decode
- URL Encode
- URL Decode
- Upper Case
- Lower Case
- Escape
- MD5
- SHA1
- SHA256
- QR Code

## xRadix
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler/master/GIFs/xRadix.gif)
- Hex
- Bin
- Oct
- Dec

## xColor
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler/master/GIFs/xColor.gif)
- Hex
- RGB
- Preview

## xSearch
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler/master/GIFs/xSearch.gif)
- Google
- Translate
- Developer
- StackOverflow
- GitHub
- Dash
- Dictionary

## xFormat
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler/master/GIFs/xFormat.gif)
- JSON
- XML
- CSS
- SQL

感谢：[vkBeautify](https://github.com/vkiryukhin/vkBeautify)

# 用法
1. 安装 Xcode 8
2. 编译运行项目
3. 选择 Xcode 8 进行调试
4. 选择文本
5. 在 Editor 菜单中找到插件
6. 你可以给每个插件都设置一个独立的快捷键
7. 这个 [WWDC Session](https://developer.apple.com/videos/play/wwdc2016/414/) 你应该会喜欢

# 如何实现一个新的 Extension
### 在 Plist 中添加定义：
```xml
<dict>
    <key>XCSourceEditorCommandClassName</key>
    <string>aClassName</string>
    <key>XCSourceEditorCommandIdentifier</key>
    <string>test.extension</string>
    <key>XCSourceEditorCommandName</key>
    <string>Test Extension</string>
</dict>
```
### 在实现类中映射你需要的处理函数：
```objc
// 在这个字典里面根据 identifier 映射 block，你可以实现一个字典单例
// @{ @"commandIdentifier": handlerBlock }
- (NSDictionary *)handlers {
    static NSDictionary *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = @{
            @"test.extension": ^NSString *(NSString *text) { return text; }
        };
    });
    return _instance;
}
```
### * 处理正则表达式
```objc
// 重写这个方法，使用 select 方法传递你需要的正则表达式
- (void)performCommandWithInvocation:(XCSourceEditorCommandInvocation *)invocation completionHandler:(void (^)(NSError * _Nullable nilOrError))completionHandler {
    [xTextModifier select:invocation pattern:@"regex" handler:self.handlers[invocation.commandIdentifier]];
    completionHandler(nil);
}
```

# TODO
- 错误处理
- App 配置面板
- JavaScript 组件
- 使用 Swift 重写项目

# 温馨提示
因为目前 Xcode 8.0 beta (8S128d) 是非常不稳定的，你在编译运行项目后可能在 Editor 里面找不到菜单 :(

# 联系方式
Weibo: [@StackOverflowError](http://weibo.com/0x00eeee/)

Twitter: [@cyanapps](https://twitter.com/cyanapps)

Email: [log.e@qq.com](mailto:log.e@qq.com)
