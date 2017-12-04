//
//  WQKVStorage.h
//  HZCityWork
//
//  Created by 王强 on 2017/12/4.
//  Copyright © 2017年 XinhuaMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN   //空值判断


@interface WQKVStorageItem : NSObject
@property (nonatomic, strong) NSString *key;                // 键
@property (nonatomic, strong) NSData *value;                // 值
@property (nullable, nonatomic, strong) NSString *filename; ///< filename (nil if inline)
@property (nonatomic) int size;                             ///< value's size in bytes
@property (nonatomic) int modTime;                          ///< modification unix timestamp
@property (nonatomic) int accessTime;                       ///< last access unix timestamp
@property (nullable, nonatomic, strong) NSData *extendedData; ///< extended data (nil if no extended data)
@end


typedef NS_ENUM(NSUInteger, WQKVStorageType) {
    
    WQKVStorageTypeFile = 0,
    
    WQKVStorageTypeSQLite = 1,
    
    WQKVStorageTypeMixed = 2,
};



@interface WQKVStorage : NSObject

#pragma mark - Attribute

@property (nonatomic, readonly) NSString *path;
@property (nonatomic, readonly) WQKVStorageType type;
@property (nonatomic) BOOL errorLogsEnabled;

#pragma mark - Initializer

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (nullable instancetype)initWithPath:(NSString *)path type:(WQKVStorageType)type NS_DESIGNATED_INITIALIZER;


#pragma mark - Save Items
- (BOOL)saveItem:(WQKVStorageItem *)item;

- (BOOL)saveItemWithKey:(NSString *)key value:(NSData *)value;

- (BOOL)saveItemWithKey:(NSString *)key
                  value:(NSData *)value
               filename:(nullable NSString *)filename
           extendedData:(nullable NSData *)extendedData;

#pragma mark - Remove Items
- (BOOL)removeItemForKey:(NSString *)key;

- (BOOL)removeItemForKeys:(NSArray<NSString *> *)keys;

- (BOOL)removeItemsLargerThanSize:(int)size;

- (BOOL)removeItemsEarlierThanTime:(int)time;

- (BOOL)removeItemsToFitSize:(int)maxSize;

- (BOOL)removeItemsToFitCount:(int)maxCount;

- (BOOL)removeAllItems;

- (void)removeAllItemsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                               endBlock:(nullable void(^)(BOOL error))end;


#pragma mark - Get Items
- (nullable WQKVStorageItem *)getItemForKey:(NSString *)key;

- (nullable WQKVStorageItem *)getItemInfoForKey:(NSString *)key;

- (nullable NSData *)getItemValueForKey:(NSString *)key;

- (nullable NSArray<WQKVStorageItem *> *)getItemForKeys:(NSArray<NSString *> *)keys;

- (nullable NSArray<WQKVStorageItem *> *)getItemInfoForKeys:(NSArray<NSString *> *)keys;

- (nullable NSDictionary<NSString *, NSData *> *)getItemValueForKeys:(NSArray<NSString *> *)keys;

#pragma mark - Get Storage Status
- (BOOL)itemExistsForKey:(NSString *)key;

- (int)getItemsCount;

- (int)getItemsSize;

@end

NS_ASSUME_NONNULL_END
