# SMART_DRAWER

## 👋 프로젝트 소개
> **음성인식 기반 무선 스마트 수납함 서비스**
- **프로젝트 기간** : 2022.01 ~ 2022.07
- [진행 과정 시행 착오.txt](https://github.com/JiMin4210/smart_drawer/blob/main/%EC%A7%84%ED%96%89%20%EA%B3%BC%EC%A0%95.txt)


## :movie_camera: 졸업 논문 및 동작 영상
#### 졸업 논문
- [음성인식 기술 기반 IoT 물품 수납함_박지건,김지민,신대혁,김지헌.pdf](https://github.com/JiMin4210/smart_drawer/files/10410340/IoT._.pdf)

#### 동작 영상
- [Smart_Drawer 동작영상](https://youtu.be/jbE87-5AnNM)

## :books: 얻은 역량
- Linux 환경에서의 프로그래밍 능력
- Shell script에 대한 이해와 활용 능력
- MPU(Raspberry pi) 활용 능력
- 오픈 소스 API 활용과 분석 능력
- Docker에 대한 이해
- Step Motor에 대한 이해

## ⭐ 기능
- 음성을 통한 물건 **등록, 삭제, 물건 위치 변경, 찾기 기능**을 수행한다.

- 찾기 기능 수행 시 step 모터를 통해 해당 위치의 **서랍을 열어주는 기능**을 수행한다.

- 마이크와 서랍의 공간 분리를 통해 같은 WIFI에만 연결되어 있다면 **어디서든 서랍 제어**가 가능하다.

## :pushpin: 기대효과
- 물건을 일일이 열어보며 찾아야하는 불필요한 작업을 줄여 **작업의 효율성이 증가**한다.

- 대표적으로 대용량 물류창고 및 산업현장과 같은 다수의 부품을 사용하는 공간에서 이용 시 **효율이 극대화** 된다.

- 거동이 불편하거나 기억력이 좋지않은 노약자나 장애인들이 **더욱 편하게 물건을 수납** 할 수 있다.

- 편의성을 추구하는 현대 시대의 **소비자들의 욕구를 충족** 시켜준다.

## 🔧 시스템 구조
<img src="https://user-images.githubusercontent.com/90883534/215079668-f6da27ef-cc7c-46c3-8aed-062187f4a2dc.png" width="700" height="400"/>

## 🔨 사용 보드
- **Raspberry Pi3** : 마이크 제어, 스피커 제어, MQTT 통신 서버 제어
- **Esp8266** : MQTT 통신
- **Arduino Uno** : step 모터 제어

## ⚡ 사용 기술
- **Docker** : MQTT 서버 제작
- **Google Assistant** : 음성 인식
- **WIFI** : google sever 연결, 마이크와 서랍의 공간 분리 목적
- **Bluetooth** : Bluetooth 스피커 연결

## 📝 사용 언어
- **Python** : 음성인식, MQTT 통신
- **C** : esp8266 보드 통신, step 모터 제어
- **Shell script** : 프로그램 꺼짐 감지 후 실행, 마이크 감도 조절, Bluetooth 스피커 꺼짐 감지 후 자동 실행
  - [run.sh](https://github.com/JiMin4210/smart_drawer/blob/main/assistant/run.sh)

## 🔆 개발 환경
- **Raspbian**
- **Visul Studio Code**




