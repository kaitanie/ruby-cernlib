=begin RD

= HBook2 拡張ライブラリ

CERNLIB の HBOOK パッケージを用いたヒストグラムライブラリ。
モジュール CERN::HBook2 の下に、各種ヒストグラムクラスや
N-tuple クラス、ディレクトリストリームクラス等が定義されます。


= HBook2

CERNLIB の HBOOK パッケージを用いたヒストグラムモジュール。

== モジュール関数:

--- HBook2.exist?(id)
      ID ((|id|)) のヒストグラムがメモリ上に存在すれば真を返します。
--- HBook2.merge(srces, dest)
      配列 ((|srces|)) で与えられたファイルを順番に読み込んでマージし、
      新しいファイル ((|dest|)) に書き込みます。
--- HBook2.read_all(filename)
      ファイル ((|filename|)) に含まれる全てのヒストグラムを読み込み、
      ((<Hist1>))、((<Hist2>))、((<Profile>))、((<Ntuple>)) クラス
      それぞれのオブジェクトの配列（二重配列）を返します。
      ファイル ((|filename|)) が存在しない場合は例外が発生します。
--- HBook2.write_all(filename)
      メモリ上に存在する全てのヒストグラムをファイル ((|filename|)) に
      書き込みます。


= BasicHist

各種ヒストグラムクラスの親となる抽象クラス。

== スーパークラス:

* Data

== メソッド:

--- BasicHist#+(other)
--- BasicHist#-(other)
--- BasicHist#*(other)
--- BasicHist#/(other)
      ヒストグラムの各チャンネル毎に演算を行い、
      その結果をヒストグラムにして返します。
      結果のヒストグラムの ID は自動的に決定されますので、
      通常はこの後に明示的に (({((<BasicHist#id=>))})) メソッドで
      指定してやる必要があります。
--- BasicHist#copy(id[, title])
      ヒストグラムを ID ((|id|)) にコピーして返します。
      引数 ((|title|)) が与えられた場合はタイトルをそれに設定します。
--- BasicHist#delete
      ヒストグラムをメモリ上から削除します。
      削除されたヒストグラムにアクセスしようとすると例外が発生します。
--- BasicHist#deleted?
      ヒストグラムが削除されている場合真を返します。
--- BasicHist#entry
      ヒストグラムのエントリー数を返します。
--- BasicHist#hist_id
      ヒストグラムの ID を返します。
--- BasicHist#hist_id=(id)
      ヒストグラムの ID を ((|id|)) に変更します。
--- BasicHist#max
      ヒストグラムの channel の中身の最大値を返します
      （overflow、underflow は除く）。
--- BasicHist#min
      ヒストグラムの channel の中身の最小値を返します
      （overflow、underflow は除く）。
--- BasicHist#reset([title])
      ヒストグラムの全ての bin を 0 にリセットします。
      引数 ((|title|)) が与えられた場合はタイトルも変更します。
--- BasicHist#sum
      ヒストグラムの全 channel の中身の合計を返します
      （overflow、underflow は除く）。
--- BasicHist#title
      ヒストグラムのタイトルを文字列として返します。
--- BasicHist#write(filename)
      ヒストグラムをファイル ((|filename|)) に書き込みます。


= Hist1

1次元ヒストグラムクラス。

== スーパークラス:

* ((<BasicHist>))

== クラスメソッド:

--- Hist1.new(id, title, bin, min, max)
      ID ((|id|))、タイトル ((|title|))、チャンネル数 ((|bin|))、
      下限 ((|min|))、上限 ((|max|)) の等間隔 bin の1次元ヒストグラム
      を返します。
--- Hist1.func(id, title, bin, min, max, func)
--- Hist1.func(id, title, bin, min, max) { ... }
      ID ((|id|))、タイトル ((|title|))、チャンネル数 ((|bin|))、
      下限 ((|min|))、上限 ((|max|)) の等間隔 bin の1次元ヒストグラム
      を作り、そこに関数 ((|func|)) あるいはブロックを評価した値を
      fill して返します。
--- Hist1.read(id, filename)
      ファイル ((|filename|)) から ID ((|id|)) の1次元ヒストグラム
      を読み出して返します。ファイル ((|filename|)) が存在しない場合は
      例外が発生します。ファイル ((|filename|)) 内に 
      ID ((|id|)) のヒストグラムが存在しない場合や、
      存在しても1次元ヒストグラムでない場合は (({nil})) を返します。

== メソッド:

--- Hist1#<<(x)
--- Hist1#fill(x[, inc])
      値 ((|x|)) に対応する bin を ((|inc|)) だけ増やします。
      ((|inc|)) のデフォルト値は 1 です。
      あるいは ((|x|)) が配列の場合は、ヒストグラムの各 channel を
      配列の中身の分だけ増やします。
--- Hist1#[](xch)
--- Hist1#content(xch)
      ((|xch|)) 番目の channel の中身を返します。
      ((|xch|)) が 0 以下の場合は underflow を、
      ヒストグラムの channel 数より大きい場合は overflow を返します。
--- Hist1#equiv
      ヒストグラムの equivalent event の数を返します
      （overflow、underflow は除く）。
--- Hist1#err2a
--- Hist1#unpack_err
      ヒストグラムの各 channel の誤差を配列として返します。
--- Hist1#error(xch)
      ((|xch|)) 番目の channel の誤差を返します。
--- Hist1#fit(par, func[, option])
--- Hist1#fit(par[, option]) { ... }
      ヒストグラムを関数 ((|func|)) で fit し、結果のパラメータと
      その誤差、及びχ二乗値を返します。第1引数 ((|par|)) には
      初期パラメータを与えます。fitting 関数 ((|func|)) は Proc オブジェクトか
      以下の文字列のいずれかです。
      * "G" Gauss 分布
      * "E" exponential
      * "P((|n|))" ((|n|))次多項式
      またブロックで与えることも出来ます。
--- Hist1#mean
      ヒストグラムの平均値を返します
      （overflow、underflow は除く）。
--- Hist1#overflow
      ヒストグラムの上限より大きいエントリーの合計を返します。
--- Hist1#pack(ary)
      ヒストグラムの各 channel の中身を配列 ((|ary|)) の中身で置き換えます。
--- Hist1#pack_err(ary)
      ヒストグラムの各 channel の誤差を配列 ((|ary|)) の中身で置き換えます。
--- Hist1#random
      ヒストグラムを確率分布とする乱数を返します。
--- Hist1#sigma
      ヒストグラムの標準偏差を返します
      （overflow、underflow は除く）。
--- Hist1#to_a
--- Hist1#unpack
      ヒストグラムの各 channel の中身を配列として返します。
--- Hist1#underflow
      ヒストグラムの下限より小さいエントリーの合計を返します。


= Hist2

2次元ヒストグラムクラス。

== スーパークラス:

* ((<BasicHist>))

== クラスメソッド:

--- Hist2.new(id, title, xbin, xmin, xmax, ybin, ymin, ymax)
      ID ((|id|))、タイトル ((|title|))、x と y 方向のチャンネル数、
      下限、上限がそれぞれ ((|xbin|))、((|xmin|))、((|xmax|)) と 
      ((|ybin|))、((|ymin|))、((|ymax|)) の等間隔 bin の
      2次元ヒストグラムを返します。
--- Hist2.read(id, filename)
      ファイル ((|filename|)) から ID ((|id|)) の2次元ヒストグラム
      を読み出して返します。ファイル ((|filename|)) が存在しない場合は
      例外が発生します。ファイル ((|filename|)) 内に 
      ID ((|id|)) のヒストグラムが存在しない場合や、
      存在しても2次元ヒストグラムでない場合は (({nil})) を返します。

== メソッド:

--- Hist2#[](xch, ych)
--- Hist2#content(xch, ych)
      x、y についてそれぞれ ((|xch|)) 番目、
      ((|ych|)) 番目の channel の中身を返します。
      ((|xch|))、((|ych|)) が 0 以下の場合は underflow を、
      ヒストグラムの channel 数より大きい場合は overflow を返します。
--- Hist2#book_xproj
      ヒストグラムに属する、X 軸方向への projection ヒストグラムを生成します。
      ただし、book した時点では何も fill されません。
      2次元ヒストグラムに fill すると、自動的にそれに属する
      projection ヒストグラムにも fill されます。
--- Hist2#book_yproj
      ヒストグラムに属する、Y 軸方向への projection ヒストグラムを生成します。
--- Hist2#book_xband(min, max)
      y の値が ((|min|)) と ((|max|)) の間だけに限定した、
      band 型の X 軸方向への projection ヒストグラムを生成します。
--- Hist2#book_yband(min, max)
      x の値が ((|min|)) と ((|max|)) の間だけに限定した、
      band 型の Y 軸方向への projection ヒストグラムを生成します。
--- Hist2#book_xslice(num)
      2次元ヒストグラムを ((|num|)) 個に slice した
      band 型の X 軸方向への projection ヒストグラムを生成します。
--- Hist2#book_yslice(num)
      2次元ヒストグラムを ((|num|)) 個に slice した
      band 型の Y 軸方向への projection ヒストグラムを生成します。
--- Hist2#err2a([option[, num]])
--- Hist2#unpack_err([option[, num]])
      ((|option|)) に (({"HIST"})) を指定した場合、
      あるいは省略した場合は、ヒストグラムの各 channel の誤差を
      二次元配列として返します。
      (({"PROX"}))、(({"PROY"}))、(({"BANX"}))、
      (({"BANY"}))、(({"SLIX"}))、(({"SLIY"}))
      を指定した場合は、それぞれ x 又は y 軸方向への projection、
      band、slice ヒストグラムの誤差を配列にして返します。
      Hist2 クラスのインスタンス (({hist2})) に対して、
      (({hist2.err2a[2][4]})) は (({hist2.error(5, 3)})) と
      同じ結果になります（が、おそい）。
--- Hist2#error(xch, ych)
      x、y についてそれぞれ ((|xch|)) 番目、
      ((|ych|)) 番目の channel の誤差を返します。
--- Hist2#fill(x, y[, inc])
      値 (((|x|)), ((|y|))) に対応する bin を ((|inc|)) だけ
      増やします。((|inc|)) のデフォルト値は 1 です。
--- Hist2#fill(ary)
      ヒストグラムの各 channel を二次元配列 ((|ary|)) の中身の分だけ
      増やします。
--- Hist2#pack(ary)
      ヒストグラムの中身を二次元配列 ((|ary|)) の中身で置き換えます。
--- Hist2#pack_err(ary)
      ヒストグラムの誤差を二次元配列 ((|ary|)) の中身で置き換えます。
--- Hist2#random
      ヒストグラムを確率分布とする二次元の乱数を返します。
--- Hist2#to_a([option[, num]])
--- Hist2#unpack([option[, num]])
      ((|option|)) に (({"HIST"})) を指定した場合、
      あるいは省略した場合はヒストグラムの各 channel の中身を
      二次元配列として返します。
      (({"PROX"}))、(({"PROY"}))、(({"BANX"}))、
      (({"BANY"}))、(({"SLIX"}))、(({"SLIY"}))
      を指定した場合は、それぞれ x 又は y 軸方向への projection、
      band、slice ヒストグラムの中身を配列にして返します。
      Hist2 クラスのインスタンス (({hist2})) に対して、
      (({hist2.to_a[2][4]})) は (({hist2.contents(5, 3)})) と
      同じ結果になります（が、おそい）。
--- Hist2#xproj(id, title)
      ヒストグラムを X 軸方向に project した結果の1次元ヒストグラムを
      返します。(({((<Hist2#book_xproj>))})) とは違い、
      ID ((|id|))、タイトル ((|title|)) の新しい
      1次元ヒストグラムを生成し、それを、その時点での
      2次元ヒストグラムの中身で fill します。
--- Hist2#yproj(id, title)
      ヒストグラムを Y 軸方向に project した結果の1次元ヒストグラムを
      返します。


= Profile

プロファイルヒストグラムクラス。

== スーパークラス:

* ((<BasicHist>))

== クラスメソッド:

--- Profile.new(id, title, xbin, xmin, xmax, ymin, ymax[, option])
      ID ((|id|))、タイトル ((|title|))、チャンネル数
      ((|xbin|))、x と y 方向の下限、上限がそれぞれ 
      ((|xmin|))、((|xmax|)) と ((|ymin|))、((|ymax|))
      の等間隔 bin のプロファイルヒストグラムを返します。
--- Profile.read(id, filename)
      ファイル ((|filename|)) から ID ((|id|))
      のプロファイルヒストグラムを読み出して返します。
      ファイル ((|filename|)) が存在しない場合は
      例外が発生します。ファイル ((|filename|)) 内に 
      ID ((|id|)) のヒストグラムが存在しない場合や、
      存在してもプロファイルヒストグラムでない場合は (({nil})) を返します。

== メソッド:

--- Profile#[](xch)
--- Profile#content(xch)
      ((|xch|)) 番目の channel の中身を返します。
      ((|xch|)) が 0 以下の場合は underflow を、
      ヒストグラムの channel 数より大きい場合は overflow を返します。
--- Profile#err2a
--- Profile#unpack_err
      ヒストグラムの各 channel の誤差を配列として返します。
--- Profile#error(xch)
      ((|xch|)) 番目の channel の誤差を返します。
--- Profile#fill(x, y[, inc])
      値 (((|x|)), ((|y|))) に対応する bin を ((|inc|)) だけ
      増やします。((|inc|)) のデフォルト値は 1 です。
--- Profile#fit(par, func[, option])
--- Profile#fit(par[, option]) { ... }
      ヒストグラムを関数 ((|func|)) で fit し、結果のパラメータと
      その誤差、及びχ二乗値を返します。各引数の意味は
      (({((<Hist1#fit>))})) のものと同じです。
--- Profile#to_a
--- Profile#unpack
      ヒストグラムの各 channel の中身を配列として返します。


= Ntuple

Row-Wise N-tuple と Column-Wise N-tuple の親となる抽象クラス。

== スーパークラス:

* Data

== インクルードしているモジュール:

* Enumerable

== メソッド:

--- Ntuple#delete
      N-tuple をメモリ上から削除します。
      削除された N-tuple にアクセスしようとすると例外が発生します。
--- Ntuple#deleted?
      N-tuple が削除されている場合真を返します。
--- Ntuple#entry
--- Ntuple#length
--- Ntuple#size
      N-tuple のイベントのエントリー数を返します。
--- Ntuple#ntuple_id
      N-tuple の ID を返します。
--- Ntuple#reset([title])
      N-tuple をリセットします。
      引数 ((|title|)) が与えられた場合はタイトルも変更します。
--- Ntuple#title
      N-tuple のタイトルを文字列として返します。


= RWNtuple

Row-Wise N-tuple クラス。

== スーパークラス:

* ((<Ntuple>))

== クラスメソッド:

--- RWNtuple.new(id, title, dir, memory, member1, ...)
      ID ((|id|))、タイトル ((|title|)) の Row-Wise N-tuple を
      ディレクトリ ((|dir|)) 上に生成して返します。

== メソッド:

--- RWNtuple#[](event)
--- RWNtuple#get_event(event)
      ((|event|)) 番目のイベントをハッシュにして返します。
--- RWNtuple#<<(data)
--- RWNtuple#fill(data)
      ハッシュとして渡されたイベントデータ ((|data|)) を
      N-tuple に fill します。
--- RWNtuple#copy(id[, title])
      同じメンバーを持った、ID ((|id|)) の N-tuple を生成して返します。
      イベントエントリーはコピーされません。
      引数 ((|title|)) が与えられた場合はタイトルをそれに設定します。
--- RWNtuple#each { |var| ... }
      N-tuple の各イベントのデータでブロックを評価します。
--- RWNtuple#fill_hist1(member, hist[, from, to])
--- RWNtuple#fill_hist1(member, hist[, from, to]) { ... }
      1次元ヒストグラム ((|hist|)) に
      N-tuple のイベント番号 ((|from|)) から ((|to|)) までの
      メンバー ((|member|)) の値を fill します。
      ブロックが与えられている場合は
      fill する際の重み関数としてそれを用います。
      単にあるメンバーの値をそのまま fill するだけならば、
      (({((<Ntuple#projection>))})) を使うよりもこちらの方が圧倒的に高速です。
--- RWNtuple#fill_hist2(xmember, ymember, hist[, from, to])
--- RWNtuple#fill_hist2(xmember, ymember, hist[, from, to]) { ... }
      2次元ヒストグラム ((|hist|)) に
      N-tuple のイベント番号 ((|from|)) から ((|to|)) までの
      メンバー ((|xmember|))、((|ymember|)) の値の組を fill します。
      引数 ((|func|)) やブロックが与えられている場合は
      fill する際の重み関数としてそれを用います。
--- RWNtuple#max(member)
      N-tuple のメンバー ((|member|)) の最大値を返します
--- RWNtuple#members
      N-tuple の各メンバー名を配列にして返します。
--- RWNtuple#min(member)
      N-tuple のメンバー ((|member|)) の最小値を返します
--- RWNtuple#projection(hist) { ... }
      N-tuple の1イベント分を格納したハッシュを引数としてブロックを
      評価し、その結果をヒストグラム ((|hist|)) に fill します。
      2次元配列やプロファイルヒストグラムに fill する場合は、
      ブロックで (({[ x, y ]})) の形の配列を返す必要があります。
      ブロックで (({nil})) を返したイベントは fill されません。


= CWNtuple

Column-Wise N-tuple クラス。
イベントブロッククラス ((<CWNBlock>)) と結びつけて使います。
  rzfile = CERN::HBook2::RZFile.open("test.rz", "topdir", "N")
  cwntuple = CERN::HBook2::CWNtuple.new(10, "CWNtuple", rzfile)
  EventBlk = CERN::HBook2::CWNBlock.new("EventBlk", "x:r", "y:r", "n:i")
  cwntuple.set_block EventBlk
  block = EventBlk.new
  block.x = 1.5
  block.y = 3.6
  block.n = 100
  cwntuple << block
もしくは
  rzfile = CERN::HBook2::RZFile.open("test.rz", "topdir", "N")
  cwntuple = CERN::HBook2::CWNtuple.new(10, "CWNtuple", rzfile)
  EventBlk = CERN::HBook2::CWNBlock.new("EventBlk", "x:r", "y:r", "n:i")
  cwntuple.set_block EventBlk
  EventBlk.x = 1.5
  EventBlk.y = 3.6
  EventBlk.z = 100
  cwntuple.fill_all

== スーパークラス:

* ((<Ntuple>))

== クラスメソッド:

--- CWNtuple.new(id, title, dir)
      ID ((|id|))、タイトル ((|title|)) の Coulmn-Wise N-tuple を
      ディレクトリ ((|dir|)) 上に生成して返します。

== メソッド:

--- CWNtuple#[](event)
--- CWNtuple#get_event(event[, block])
      ((|event|)) 番目のイベントをイベントブロックの配列にして返します。      
      イベントブロッククラス ((|block|)) が与えられた場合は
      そのイベントブロックのイベントだけを返します。
--- CWNtuple#<<(data)
--- CWNtuple#fill(data)
      イベントブロック ((|data|)) にまとめられたデータを
      N-tuple に fill します。
--- CWNtuple#each { ... }
      各イベントについてイベントブロックの配列でブロックを評価します。
--- CWNtuple#fill_all
      N-tuple に結びつけられた全てのイベントブロックにまとめられたデータを
      N-tuple に fill します。
--- CWNtuple#blocks
      N-tuple に結びつけられているブロックを配列にして返します。
--- CWNtuple#set_block(block)
      イベントブロッククラス ((|block|)) を N-tuple に結びつけます。


= CWNBlock

Column-wise N-tuple に fill するイベントをまとめた
構造体（ブロック）クラス。
Struct のように、((<CWNBlock.new>)) メソッドにより
自分の子クラスを新たに生成します。

== スーパークラス:

* Data

== インクルードしているモジュール:

* Enumerable

== クラスメソッド:

--- CWNBlock.new(name, member1, member2, ...)
      名前 ((|name|)) の イベントブロッククラスを
      生成して返します。

== メソッド:

--- CWNBlock#members
      イベントブロックのメンバー名を配列にして返します。
--- CWNBlock#each { ... }
      イベントブロックの各メンバーの値でブロックを評価します。
--- CWNBlock#length
--- CWNBlock#size
      イベントブロックのメンバーの数を返します。
--- CWNBlock#to_a
--- CWNBlock#values
      イベントブロックの各メンバーの値を配列にして返します。


= RZDir

HBOOK directory stream クラス。

== スーパークラス:

* Data

== インクルードしているモジュール:

* Enumerable

== クラスメソッド:

--- RZDir.new([dir])
--- RZDir.open([dir])
--- RZDir.open([dir]) { |rzdir| ... }
      ディレクトリ名 ((|dir|)) のディレクトリストリームを開きます。
      引数 ((|dir|)) のデフォルト値はカレントディレクトリです。
      open() はブロックを指定することができ、その場合は、
      ディレクトリストリームを引数にしてブロックを評価し、
      その結果を返します。
      ブロックの実行が終了すると、ディレクトリは自動的にクローズされます。
--- RZDir.chdir(dir)
      カレントディレクトリを ((|dir|)) に変更します。
--- RZDir.delete(dir)
--- RZDir.rmdir(dir)
      ((|dir|)) というディレクトリを削除します。
--- RZDir.entries(dir)
      ディレクトリ ((|dir|)) の全要素を配列にして返します。
--- RZDir.expand_path(dir)
      ディレクトリ ((|dir|)) のフルパス名を返します。
--- RZDir.foreach(dir) { |item| ... }
      ディレクトリ ((|dir|)) の各要素に対してブロックを評価します。
--- RZDir.list([dir])
      ディレクトリ ((|dir|)) の全要素のリストを標準出力に出力します。
      ((|dir|)) のデフォルト値はカレントディレクトリです。
--- RZDir.getwd
--- RZDir.pwd
      カレントディレクトリのフルパス名を返します。
--- RZDir.mkdir(dir)
      ((|dir|)) という新しいディレクトリを作って、
      そのディレクトリストリームを返します。

== メソッド:

--- RZDir#[](id)
      ディレクトリ内にある ID ((|id|)) のヒストグラム又は N-tuple を返します。
--- RZDir#<<(hist)
--- RZDir#write(hist)
      ヒストグラム ((|hist|)) をディレクトリに書き込みます。
      ディレクトリはファイル上のものでなければなりません。
--- RZDir#close
      ディレクトリストリームを閉じます。閉じた後にそのディレクトリに
      アクセスしようとすると例外が発生します。
--- RZDir#closed?
      ディレクトリストリームがすでに閉じている場合に (({true})) を返します。
--- RZDir#each { |item| ... }
      ディレクトリストリームの各要素に対してブロックを評価します。
--- RZDir#read
      ディレクトリストリームから次の要素を返します。
--- RZDir#rewind
      ディレクトリストリームの読み込み位置を先頭に戻します。
--- RZDir#to_s
      ディレクトリパスを文字列として返します。
--- RZDir#write_all
      メモリ上の全ヒストグラムと全 N-tuple をディレクトリに書き込みます。
      ディレクトリはファイル上のものでなければなりません。


= RZFile

RZ file クラス。

== スーパークラス:

* ((<RZDir>))

== クラスメソッド:

--- RZFile.new(filename[, topdir[, option]])
--- RZFile.open(filename[, topdir[, option]])
--- RZFile.open(filename[, topdir[, option]]) { |rzfile| ... }
      ファイル名 ((|filename|)) の RZ file を open して、
      ディレクトリ名 ((|topdir|)) としてマウントし、
      そのディレクトリストリームを返します。
      ((|topdir|)) が省略された場合は、
      lun1、lun2、…、のように適当に決められます。
      open() はブロックを指定することができ、その場合は、
      開いた RZ file のディレクトリストリームを引数にして
      ブロックを評価し、その結果を返します。
      ブロックの実行が終了すると、RZ file は自動的にクローズされます。

== メソッド:

--- RZFile#close
      RZ file を閉じます。閉じた後にその RZ file にアクセスしようとすると
      例外が発生します。
--- RZFile#filename
      ファイル名を返します。
--- RZFile#lun
      ファイル番号を返します。
--- RZFile#option
      開くときにオプションとして渡した文字列を返します。
--- RZFile#topname
      トップディレクトリ名を返します。

=end
