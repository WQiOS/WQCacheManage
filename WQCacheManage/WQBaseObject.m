//
//  WQBaseObject.m
//  HZCityWork
//
//  Created by 王强 on 2017/12/4.
//  Copyright © 2017年 XinhuaMobile. All rights reserved.
//

#import "WQBaseObject.h"
#import <YYModel/YYModel.h>

@implementation WQBaseObject

- (id)initWithCoder:(NSCoder *)aDecoder{
    return [self yy_modelInitWithCoder:aDecoder];
}

- (void)encodeWithCoder:(NSCoder *)aCoder{
    [self yy_modelEncodeWithCoder:aCoder];
}

@end
