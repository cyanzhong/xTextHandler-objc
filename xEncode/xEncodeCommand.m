//
//  xEncodeCommand.m
//  xEncode
//
//  Created by cyan on 16/6/18.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import "xEncodeCommand.h"
#import "xEncode.h"

@implementation xEncodeCommand

- (NSDictionary *)handlers {
    static NSDictionary *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = @{
            @"xencode.base64encode": ^NSString *(NSString *text) { return Base64Encode(text); },
            @"xencode.base64decode": ^NSString *(NSString *text) { return Base64Decode(text); },
            @"xencode.urlencode": ^NSString *(NSString *text) { return URLEncode(text); },
            @"xencode.urldecode": ^NSString *(NSString *text) { return URLDecode(text); },
            @"xencode.uppercase": ^NSString *(NSString *text) { return Uppercase(text); },
            @"xencode.lowercase": ^NSString *(NSString *text) { return Lowercase(text); },
            @"xencode.escape": ^NSString *(NSString *text) { return Escape(text); },
            @"xencode.md5": ^NSString *(NSString *text) { return MD5(text); },
            @"xencode.sha1": ^NSString *(NSString *text) { return SHA1(text); },
            @"xencode.sha256": ^NSString *(NSString *text) { return SHA256(text); },
            @"xencode.qrcode": ^NSString *(NSString *text) { return QRCode(text); },
        };
    });
    return _instance;
}

@end
