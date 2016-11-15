# Dragon-AVideo-Servers Design

## 背景
主要自适应音视频传输服务设计,适于WebRTC框架，但不局限于WebRTC传输；

## 原则
1. 最大满足的音视频传输的需要，不做第三方业务处理（例如：IM，数据共享等等）；
2. 提供灵活的对外API接口；
3. 需要与第三方媒体数据服务器对接；

## 相关技术和协议
- TCP/UDP
- RTP/RTCP
- SDP
- TURN
- OPUS H.264

## 整体设计
### 框架
1. 主程
2. 线程
3. 配置

### 网络基础库
- libevent