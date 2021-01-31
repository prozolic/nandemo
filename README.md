# 1. nandemo(文字列変換ライブラリ)

[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE)

## 1.1. nandemoとは
nandemoは, C++のオブジェクトを文字列に変換するライブラリです。
* 数値を文字列に変換（2進数 10進数 16進数）
* 論理型（bool）から文字列に変換
* クラス（class）, 構造体（struct）から文字列に変換
* カスタム文字列を返す拡張も可能

## 1.2. 特徴
* C++17以上
* シングルヘッダーオンリー
* [MIT License](LICENSE)


## 1.3. 利用方法
最新版の[nandemo.h](nandemo.h)をダウンロードすることで利用可能です。

## 1.4. サンプル
### 1.4.1. 数値型, 論理型, 文字列型
```cpp
// integer type
int value{999};
nandemo::to_string(value); // "999"

// float point type
float f_value{1.0f};
nandemo::to_string(f_value); // "1.000000"

// bool type
bool b_value{true};
nandemo::to_string(b_value); // "true"

// char type
char c_value{'n'};
nandemo::to_string(c_value); // "n"

// string type
std::string s_value{"this is string"};
nandemo::to_string(s_value); // "this is string"

// string_view type
std::string_view sv_value{"this is string_view"};
nandemo::to_string(sv_value); // "this is string_view"

```

### 1.4.2. 数値型 -> 2進数 or 10進数 or 16進数
```cpp
int value{123};
nandemo::to_string_numeric<nandemo::base::decimal>(value); // 123

nandemo::to_string_decimal(value); // 123

nandemo::to_string_numeric<nandemo::base::binary>(value); // 00000000000000000000000001111011

nandemo::to_string_binary(value); // 00000000000000000000000001111011

nandemo::to_string_numeric<nandemo::base::hex>(value); // 7b

nandemo::to_string_hex(value); // 7b

```

### 1.4.3. 数値型 -> 2進数 or 10進数 or 16進数（"0"文字補完）
```cpp
int value{123};
nandemo::to_string_numeric<nandemo::base::decimal,5>(value); // 00123

nandemo::to_string_decimal<5>(value); // 00123

nandemo::to_string_numeric<nandemo::base::hex,5>(value); // 0007b 

nandemo::to_string_hex<5>(value); // 0007b

```

### 1.4.4. クラス, 構造体
```cpp
class test_class{};
struct test_struct{};

test_class c_value;
std::string result = nandemo::to_string(c_value); // "test_class"

test_struct s_value;
std::string result = nandemo::to_string(s_value); // "test_struct"

```

### 1.4.5. カスタム文字列
```cpp
class test_class
{
public:
    std::string to_string() const
    {
        return "this is test_class.";
    }
};

test_class c_value;
std::string result = nandemo::to_string(c_value); // "this is test_class."

```

## 1.5. 実行確認コンパイラ
* gcc 10.1.0
* clang 10.0.0

## 1.6. テスト  
テストソースは[test.cpp](test.cpp)を参照してください。  
テストには、[Catch](https://github.com/catchorg/Catch2)ライブラリを使用しています。  
