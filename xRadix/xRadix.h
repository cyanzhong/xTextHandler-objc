//
//  xRadix.h
//  xTextHandler
//
//  Created by cyan on 16/6/18.
//  Copyright © 2016年 cyan. All rights reserved.
//

typedef NS_ENUM(NSInteger, xTextRadixType) {
    xTextRadixTypeDec           = 10,
    xTextRadixTypeHex           = 16,
    xTextRadixTypeBin           = 2,
    xTextRadixTypeOct           = 8,
};

static inline xTextRadixType RadixType(NSString *string) {
    
    if ([string hasPrefix:@"#"] || [string hasPrefix:@"0x"]) {
        return xTextRadixTypeHex;
    }
    
    if ([string hasPrefix:@"0"]) {
        return xTextRadixTypeOct;
    }
    
//    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"0|1"
//                                                                           options:0
//                                                                             error:nil];
//    NSString *modified = [regex stringByReplacingMatchesInString:string
//                                                         options:0
//                                                           range:NSMakeRange(0, string.length)
//                                                    withTemplate:@""];
//    if (modified.length == 0) {
//        return xTextRadixTypeBin;
//    }
    
    return xTextRadixTypeDec;
}

static inline NSString *Dec(NSString *string) {
    
    xTextRadixType type = RadixType(string);
    NSScanner *scanner = [NSScanner scannerWithString:string];
    
    switch (type) {
        case xTextRadixTypeHex: {
            if ([string hasPrefix:@"#"]) {
                scanner.scanLocation = 1;
            }
            unsigned result;
            [scanner scanHexInt:&result];
            return [@(result) stringValue];
        }
        case xTextRadixTypeBin:
        case xTextRadixTypeOct: {
            const char *utf8 = string.UTF8String;
            char *endPtr = NULL;
            return [@(strtol(utf8, &endPtr, type)) stringValue];
        }
            
        default: return string;
    }
}

static inline NSString *Hex(NSString *string) {
    return [NSString stringWithFormat:@"0x%X", Dec(string).intValue];
}

static inline NSString *Bin(NSString *string) {
    NSMutableString *str = [NSMutableString string];
    for (int number = Dec(string).intValue; number > 0; number >>= 1) {
        [str insertString:((number & 1) ? @"1" : @"0") atIndex:0];
    }
    return str;
}

static inline NSString *Oct(NSString *string) {
    return [NSString stringWithFormat:@"0%o", Dec(string).intValue];
}
