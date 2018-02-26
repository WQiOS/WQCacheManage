//
//  WQDiskCache.h
//  HZCityWork
//
//  Created by 王强 on 2017/12/4.
//  Copyright © 2017年 XinhuaMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WQDiskCache : NSObject

#pragma mark - 属性
@property (nullable, copy) NSString *name;
@property (readonly) NSString *path;
@property (readonly) NSUInteger inlineThreshold;
@property (nullable, copy) NSData *(^customArchiveBlock)(id object);
@property (nullable, copy) id (^customUnarchiveBlock)(NSData *data);
@property (nullable, copy) NSString *(^customFileNameBlock)(NSString *key);

#pragma mark - 限制
@property NSUInteger countLimit;
@property NSUInteger costLimit;
@property NSTimeInterval ageLimit;
@property NSUInteger freeDiskSpaceLimit;
@property NSTimeInterval autoTrimInterval;
@property BOOL errorLogsEnabled;

#pragma mark -  初始化

//禁止通过下面两个方式实例化对象
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**根据path 创建实例 单位对象存储默认大小20k，如果对象的数据大小(以字节为单位)大于这个值，那么对象将会存储为file文件，否则对象将存储在sqlite中。*/
- (nullable instancetype)initWithPath:(NSString *)path;
- (nullable instancetype)initWithPath:(NSString *)path
                      inlineThreshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

#pragma mark - 方法
// 判断内存和硬盘缓存 是否 包含键所对应的值
- (BOOL)containsObjectForKey:(NSString *)key;

// 判断内存和硬盘缓存 是否 包含键所对应的值 ，异步回调
- (void)containsObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block;

// 通过key取值
- (nullable id<NSCoding>)objectForKey:(NSString *)key;

// 通过key取值， 异步回调
- (void)objectForKey:(NSString *)key withBlock:(void(^)(NSString *key, id<NSCoding> _Nullable object))block;

// 存储
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

// 存储， 异步回调
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(void(^)(void))block;

// 删除
- (void)removeObjectForKey:(NSString *)key;

// 删除 ， 异步回调
- (void)removeObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key))block;

// 清空
- (void)removeAllObjects;

// 清空  异步回调
- (void)removeAllObjectsWithBlock:(void(^)(void))block;

// 清空  异步回调
- (void)removeAllObjectsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                                 endBlock:(nullable void(^)(BOOL error))end;

// 总个数
- (NSInteger)totalCount;

// 总个数 回调
- (void)totalCountWithBlock:(void(^)(NSInteger totalCount))block;

// 总大小
- (NSInteger)totalCost;

// 总大小  回调
- (void)totalCostWithBlock:(void(^)(NSInteger totalCost))block;

#pragma mark - Trim

- (void)trimToCount:(NSUInteger)count;
- (void)trimToCount:(NSUInteger)count withBlock:(void(^)(void))block;
- (void)trimToCost:(NSUInteger)cost;
- (void)trimToCost:(NSUInteger)cost withBlock:(void(^)(void))block;
- (void)trimToAge:(NSTimeInterval)age;
- (void)trimToAge:(NSTimeInterval)age withBlock:(void(^)(void))block;


#pragma mark - Extended Data
+ (nullable NSData *)getExtendedDataFromObject:(id)object;

+ (void)setExtendedData:(nullable NSData *)extendedData toObject:(id)object;

@end
NS_ASSUME_NONNULL_END
