# Let's Swift!
xTextHandler has been rewrite in Swift, Swift version can be found in: https://github.com/cyanzhong/xTextHandler

⚠️Objective-C version is no longer under maintenance

🇨🇳[中文介绍](https://github.com/cyanzhong/xTextHandler-objc/blob/master/README_CN.md)

# xTextHandler
Xcode Source Editor Extension Toolset (Plugins for Xcode 8)

# What is it
[Xcode Source Editor Extension](https://developer.apple.com/videos/play/wwdc2016/414/) based tools, improve text editing experience for Xcode 8, you can extend with simple code

# Features
- Multiline Selections
- Multiple Extensions
- Extendable API
- Clipboard Text Handling (if select nothing)
- Regular Expression Matching

## xEncode
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler-objc/master/GIFs/xEncode.gif)
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
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler-objc/master/GIFs/xRadix.gif)
- Hex
- Bin
- Oct
- Dec

## xColor
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler-objc/master/GIFs/xColor.gif)
- Hex
- RGB
- Preview

## xSearch
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler-objc/master/GIFs/xSearch.gif)
- Google
- Translate
- Developer
- StackOverflow
- GitHub
- Dash
- Dictionary

## xFormat
![image](https://raw.githubusercontent.com/cyanzhong/xTextHandler-objc/master/GIFs/xFormat.gif)
- JSON
- XML
- CSS
- SQL

Thanks to: [vkBeautify](https://github.com/vkiryukhin/vkBeautify)

# Usage
1. Install Xcode 8
2. Build & Run
3. Choose Xcode to debug
4. Select text
5. Open Editor menu to find extensions
6. You can set a shortcut (Key-Binding) for each extension
7. Maybe you will like this [WWDC Session](https://developer.apple.com/videos/play/wwdc2016/414/)

# How to write a new Extension
### Add definition in Plist:
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
### Map handler via commandIdentifier in class:
```objc
// Implement your modify strategy using block (you can implement as singleton dict)
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
### * Handle with regex:
```objc
// Override performCommandWithInvocation like that
- (void)performCommandWithInvocation:(XCSourceEditorCommandInvocation *)invocation completionHandler:(void (^)(NSError * _Nullable nilOrError))completionHandler {
    [xTextModifier select:invocation pattern:@"regex" handler:self.handlers[invocation.commandIdentifier]];
    completionHandler(nil);
}
```

# TODO
- Error handling
- Preferences panel
- JavaScript for text handling

# Tips
Since Xcode 8.0 beta (8S128d) is totally unstable now, you may see nothing after you build & run this project :(

# Contacts
Weibo: [@StackOverflowError](http://weibo.com/0x00eeee/)

Twitter: [@cyanapps](https://twitter.com/cyanapps)

Email: [log.e@qq.com](mailto:log.e@qq.com)
