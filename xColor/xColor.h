//
//  xColor.h
//  xTextHandler
//
//  Created by cyan on 16/6/19.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import <AppKit/AppKit.h>

static inline NSString *HexColor(NSString *string) {
    
    NSString *pattern = @"([0-9]+).+?([0-9]+).+?([0-9]+)";
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:pattern
                                                                           options:0
                                                                             error:nil];
    __block NSString *hex;
    [regex enumerateMatchesInString:string options:0 range:NSMakeRange(0, string.length) usingBlock:^(NSTextCheckingResult * _Nullable result, NSMatchingFlags flags, BOOL * _Nonnull stop) {
        int r = [[string substringWithRange:[result rangeAtIndex:1]] intValue];
        int g = [[string substringWithRange:[result rangeAtIndex:2]] intValue];
        int b = [[string substringWithRange:[result rangeAtIndex:3]] intValue];
        hex = [NSString stringWithFormat:@"%02X%02X%02X", r, g, b];
    }];

    return hex;
}

static inline NSString *RgbColor(NSString *string) {
    unsigned rgbValue = 0;
    NSScanner *scanner = [NSScanner scannerWithString:string];
    [scanner scanHexInt:&rgbValue];
    NSString *rgb = [NSString stringWithFormat:@"%d, %d, %d", ((rgbValue & 0xFF0000) >> 16), ((rgbValue & 0xFF00) >> 8), (rgbValue & 0xFF)];
    return rgb;
}

static inline NSString *PreviewColor(NSString *string) {
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", @"[0-9a-fA-F]+"];
    NSString *value = [predicate evaluateWithObject:string] ? string : HexColor(string);
    [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"http://hexpreview.com/%@", value]]];
    return string;
}
