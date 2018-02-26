
Pod::Spec.new do |s|

s.name         = "WQCacheManage"
s.version      = "1.0.0"
s.summary      = "Pod库"
s.description  = <<-DESC
                 自己总结的私有Pods库，欢迎使用。
                 DESC
s.homepage     = "https://github.com/WQiOS/WQCacheManage"
s.license      = "MIT"
s.author             = { "王强" => "1570375769@qq.com" }
s.platform     = :ios, "8.0" #平台及支持的最低版本
s.requires_arc = true # 是否启用ARC
s.source       = { :git => "https://github.com/WQiOS/WQCacheManage.git", :tag => "#{s.version}" }
s.source_files  = "WQCacheManage/*.{h,m}"
s.ios.framework  = 'UIKit'

end
