# 概要
* 素因数分解プログラム
* 普通の実装(試し割り法)とエラトステネスの篩との違い

# 結果
12345, 1000000007, 5368709120, 12345678987654321 の4種類

| 方法 | 12345 | 1000000007 | 5368709120 | 12345678987654321 |
|:-:|-:|-:|-:|-:|
| 試し割り | 1e-05[s] | 9.28351[s] | 1e-06[s] | 0.003057[s] |
| 試し割り(平方根) | 1e-06[s] | 0.000312[s] | 0[s] | 0.003293[s] |
| 試し割り(篩) | 2e-06[s] | 0.000214[s] | 0.000271[s] | 2.14924[s] |

# 結論
* 素数リスト，最利用しない限り篩は使わなくて良い
* 割る数を平方根までにすべき

# 参考
## 素因数分解について
* http://sucrose.hatenablog.com/entry/2014/10/10/235805

## テンプレートクラスの継承について
* https://qiita.com/kaityo256/items/2f24662a9ab8341ad6f4

## 計測について
* http://www.sanko-shoko.net/note.php?id=rnfd
