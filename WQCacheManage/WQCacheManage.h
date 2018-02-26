//
//  WQCacheManage.h
//  HZCityWork
//
//  Created by 王强 on 2017/12/4.
//  Copyright © 2017年 XinhuaMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WQMemoryCache;
@class WQDiskCache;
@class WQKVStorage;

// 空值判断
NS_ASSUME_NONNULL_BEGIN

@interface WQCacheManage : NSObject

/** 缓存的name，只读 */
@property (copy, readonly) NSString *name;

/** XYCacheManage下的内存缓存 ，先v磁盘持久化存储 再缓存存储 */
@property (strong, readonly) WQMemoryCache *memoryCache;

/**XYCacheManage下的kv磁盘持久化存储，*/
@property (strong, readonly) WQDiskCache *diskCache;

/**根据name 创建实例，默认缓存目录*/
- (nullable instancetype)initWithName:(NSString *)name;

/**根据path 创建实例*/
- (nullable instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;

/**根据name 创建实例，默认缓存目录*/
+ (nullable instancetype)cacheWithName:(NSString *)name;

/**根据path 创建实例*/
+ (nullable instancetype)cacheWithPath:(NSString *)path;

// 禁止通过下面两个方式实例化对象
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


#pragma mark - Access Methods

// 判断内存和硬盘缓存 是否 包含键所对应的值
- (BOOL)containsObjectForKey:(NSString *)key;

// 判断内存和硬盘缓存 是否 包含键所对应的值 ，异步回调
- (void)containsObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key, BOOL contains))block;

// 通过key取值
- (nullable id<NSCoding>)objectForKey:(NSString *)key;

// 通过key取值， 异步回调
- (void)objectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key, id<NSCoding> object))block;

//存储
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

//存储， 异步回调
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(nullable void(^)(void))block;

// 删除
- (void)removeObjectForKey:(NSString *)key;

// 删除 ， 异步回调
- (void)removeObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key))block;

// 清空
- (void)removeAllObjects;

// 清空 ， 异步回调
- (void)removeAllObjectsWithBlock:(void(^)(void))block;
- (void)removeAllObjectsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                                 endBlock:(nullable void(^)(BOOL error))end;

@end
NS_ASSUME_NONNULL_END
