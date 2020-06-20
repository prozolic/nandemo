# nandemo(文字列取得ライブラリ)

[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE)

## nandemoとは
nandemoは, C++のオブジェクトを文字列に変換するライブラリです。
* 数値型（integer, float point）文字列
* 論理型（bool）文字列
* クラス名（class）, 構造体名（struct）文字列
* カスタム文字列

## 特徴
* C++17以上
* シングルヘッダーオンリー
* [MIT License](LICENSE)


## 利用方法
最新版の[nandemo.h](nandemo.h)をダウンロードすることで利用可能です。

## サンプル
### 数値型, 論理型, 文字列型
```cpp
// integer type
int value{999};
nandemo::to_string(value); // "999"

// float point type
float f_value{1.0f};
nandemo::to_string(value2); // "1.000000"

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

### クラス, 構造体
```cpp
class test_class{};
struct test_struct{};

test_class c_value;
std::string result = nandemo::to_string(c_value); // "test_class"

test_struct s_value;
std::string result = nandemo::to_string(s_value); // "test_struct"

```

### カスタム文字列
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

## 実行確認コンパイラ
* gcc 10.1.0
* clang 10.0.0
