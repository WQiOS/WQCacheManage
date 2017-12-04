#
#  Be sure to run `pod spec lint WQCacheManage.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

s.name         = "WQCacheManage"
s.version      = "1.0.0"
s.summary      = "A short description of WQCacheManage."

s.description  = <<-DESC
自己总结的私有Pods库，欢迎使用。

s.homepage     = "https://github.com/WQiOS/WQCacheManage"

s.license      = "MIT"          # 开源证书

s.author             = { "王强" => "1570375769@qq.com" }

s.platform     = :ios, "8.0" #平台及支持的最低版本

s.requires_arc = true # 是否启用ARC

s.source       = { :git => "https://github.com/WQiOS/WQCacheManage.git", :tag => "#{s.version}" }

s.source_files  = "WQCacheManage/*.{h,m}"

s.ios.framework  = 'UIKit'

end
