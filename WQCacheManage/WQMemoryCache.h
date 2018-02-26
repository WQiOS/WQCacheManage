//
//  WQMemoryCache.h
//  WQCache
//
//  Created by 王强 on 2017/5/18.
//  Copyright © 2017年 王强. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WQMemoryCache : NSObject

#pragma mark - 属性

// 内存名字
@property (nullable, copy) NSString *name;

// 总个数
@property (readonly) NSUInteger totalCount;

//总大小
@property (readonly) NSUInteger totalCost;

#pragma mark - 限制

// 个数限制 默认无限制
@property NSUInteger countLimit;

//大小限制 默认无限制
@property NSUInteger costLimit;

// 内存 生命周期时间限制
@property NSTimeInterval ageLimit;

@property NSTimeInterval autoTrimInterval;

// 默认为yes ， 当 app 内存受到警告的时候删除内存
@property BOOL shouldRemoveAllObjectsOnMemoryWarning;

// 默认yes ，当app 进到后台的时候，内存会被删除
@property BOOL shouldRemoveAllObjectsWhenEnteringBackground;

// 当app 内存受到警告的时候删除内存,回调
@property (nullable, copy) void(^didReceiveMemoryWarningBlock)(WQMemoryCache *cache);

// 当app 进到后台删除内存,回调
@property (nullable, copy) void(^didEnterBackgroundBlock)(WQMemoryCache *cache);

// 是否在主线程释放对象，默认 NO，有些对象（例如 UIView/CALayer）应该在主线程释放
@property BOOL releaseOnMainThread;

// 是否异步释放对象，默认 YES
@property BOOL releaseAsynchronously;

#pragma mark - 访问方法

// 判断内存 是否 包含键所对应的值
- (BOOL)containsObjectForKey:(id)key;

// 通过key取值
- (nullable id)objectForKey:(id)key;

//存储
- (void)setObject:(nullable id)object forKey:(id)key;

//存储 结合大小
- (void)setObject:(nullable id)object forKey:(id)key withCost:(NSUInteger)cost;

// 删除
- (void)removeObjectForKey:(id)key;

// 删除 所有对象
- (void)removeAllObjects;


#pragma mark - Trim
- (void)trimToCount:(NSUInteger)count;

- (void)trimToCost:(NSUInteger)cost;

- (void)trimToAge:(NSTimeInterval)age;

@end

NS_ASSUME_NONNULL_END


