//
//  xTextProtocol.h
//  xTextHandler
//
//  Created by cyan on 16/6/18.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import <XcodeKit/XcodeKit.h>

@protocol xTextProtocol <NSObject, XCSourceEditorCommand>


/**
 Handlers map
 
 See xEncodeCommand.m for details

 @return @{ @"commandIdentifier": NSString *(^handler)(NSString *text) }
 */
- (NSDictionary *)handlers;

@end
