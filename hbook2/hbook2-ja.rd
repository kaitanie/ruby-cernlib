=begin RD

= HBook2 ��ĥ�饤�֥��

CERNLIB �� HBOOK �ѥå��������Ѥ����ҥ��ȥ����饤�֥�ꡣ
�⥸�塼�� CERN::HBook2 �β��ˡ��Ƽ�ҥ��ȥ���९�饹��
N-tuple ���饹���ǥ��쥯�ȥꥹ�ȥ꡼�९�饹�����������ޤ���


= HBook2

CERNLIB �� HBOOK �ѥå��������Ѥ����ҥ��ȥ����⥸�塼�롣

== �⥸�塼��ؿ�:

--- HBook2.exist?(id)
      ID ((|id|)) �Υҥ��ȥ���ब������¸�ߤ���п����֤��ޤ���
--- HBook2.merge(srces, dest)
      ���� ((|srces|)) ��Ϳ����줿�ե��������֤��ɤ߹���ǥޡ�������
      �������ե����� ((|dest|)) �˽񤭹��ߤޤ���
--- HBook2.read_all(filename)
      �ե����� ((|filename|)) �˴ޤޤ�����ƤΥҥ��ȥ������ɤ߹��ߡ�
      ((<Hist1>))��((<Hist2>))��((<Profile>))��((<Ntuple>)) ���饹
      ���줾��Υ��֥������Ȥ�������������ˤ��֤��ޤ���
      �ե����� ((|filename|)) ��¸�ߤ��ʤ������㳰��ȯ�����ޤ���
--- HBook2.write_all(filename)
      ������¸�ߤ������ƤΥҥ��ȥ�����ե����� ((|filename|)) ��
      �񤭹��ߤޤ���


= BasicHist

�Ƽ�ҥ��ȥ���९�饹�οƤȤʤ���ݥ��饹��

== �����ѡ����饹:

* Data

== �᥽�å�:

--- BasicHist#+(other)
--- BasicHist#-(other)
--- BasicHist#*(other)
--- BasicHist#/(other)
      �ҥ��ȥ����γƥ����ͥ���˱黻��Ԥ���
      ���η�̤�ҥ��ȥ����ˤ����֤��ޤ���
      ��̤Υҥ��ȥ����� ID �ϼ�ưŪ�˷��ꤵ��ޤ��Τǡ�
      �̾�Ϥ��θ������Ū�� (({((<BasicHist#id=>))})) �᥽�åɤ�
      ���ꤷ�Ƥ��ɬ�פ�����ޤ���
--- BasicHist#copy(id[, title])
      �ҥ��ȥ����� ID ((|id|)) �˥��ԡ������֤��ޤ���
      ���� ((|title|)) ��Ϳ����줿���ϥ����ȥ�򤽤�����ꤷ�ޤ���
--- BasicHist#delete
      �ҥ��ȥ��������夫�������ޤ���
      ������줿�ҥ��ȥ����˥����������褦�Ȥ�����㳰��ȯ�����ޤ���
--- BasicHist#deleted?
      �ҥ��ȥ���ब�������Ƥ����翿���֤��ޤ���
--- BasicHist#entry
      �ҥ��ȥ����Υ���ȥ꡼�����֤��ޤ���
--- BasicHist#hist_id
      �ҥ��ȥ����� ID ���֤��ޤ���
--- BasicHist#hist_id=(id)
      �ҥ��ȥ����� ID �� ((|id|)) ���ѹ����ޤ���
--- BasicHist#max
      �ҥ��ȥ����� channel ����Ȥκ����ͤ��֤��ޤ�
      ��overflow��underflow �Ͻ����ˡ�
--- BasicHist#min
      �ҥ��ȥ����� channel ����ȤκǾ��ͤ��֤��ޤ�
      ��overflow��underflow �Ͻ����ˡ�
--- BasicHist#reset([title])
      �ҥ��ȥ��������Ƥ� bin �� 0 �˥ꥻ�åȤ��ޤ���
      ���� ((|title|)) ��Ϳ����줿���ϥ����ȥ���ѹ����ޤ���
--- BasicHist#sum
      �ҥ��ȥ������� channel ����Ȥι�פ��֤��ޤ�
      ��overflow��underflow �Ͻ����ˡ�
--- BasicHist#title
      �ҥ��ȥ����Υ����ȥ��ʸ����Ȥ����֤��ޤ���
--- BasicHist#write(filename)
      �ҥ��ȥ�����ե����� ((|filename|)) �˽񤭹��ߤޤ���


= Hist1

1�����ҥ��ȥ���९�饹��

== �����ѡ����饹:

* ((<BasicHist>))

== ���饹�᥽�å�:

--- Hist1.new(id, title, bin, min, max)
      ID ((|id|))�������ȥ� ((|title|))�������ͥ�� ((|bin|))��
      ���� ((|min|))����� ((|max|)) �����ֳ� bin ��1�����ҥ��ȥ����
      ���֤��ޤ���
--- Hist1.func(id, title, bin, min, max, func)
--- Hist1.func(id, title, bin, min, max) { ... }
      ID ((|id|))�������ȥ� ((|title|))�������ͥ�� ((|bin|))��
      ���� ((|min|))����� ((|max|)) �����ֳ� bin ��1�����ҥ��ȥ����
      ���ꡢ�����˴ؿ� ((|func|)) ���뤤�ϥ֥�å���ɾ�������ͤ�
      fill �����֤��ޤ���
--- Hist1.read(id, filename)
      �ե����� ((|filename|)) ���� ID ((|id|)) ��1�����ҥ��ȥ����
      ���ɤ߽Ф����֤��ޤ����ե����� ((|filename|)) ��¸�ߤ��ʤ�����
      �㳰��ȯ�����ޤ����ե����� ((|filename|)) ��� 
      ID ((|id|)) �Υҥ��ȥ���ब¸�ߤ��ʤ����䡢
      ¸�ߤ��Ƥ�1�����ҥ��ȥ����Ǥʤ����� (({nil})) ���֤��ޤ���

== �᥽�å�:

--- Hist1#<<(x)
--- Hist1#fill(x[, inc])
      �� ((|x|)) ���б����� bin �� ((|inc|)) �������䤷�ޤ���
      ((|inc|)) �Υǥե�����ͤ� 1 �Ǥ���
      ���뤤�� ((|x|)) ������ξ��ϡ��ҥ��ȥ����γ� channel ��
      �������Ȥ�ʬ�������䤷�ޤ���
--- Hist1#[](xch)
--- Hist1#content(xch)
      ((|xch|)) ���ܤ� channel ����Ȥ��֤��ޤ���
      ((|xch|)) �� 0 �ʲ��ξ��� underflow ��
      �ҥ��ȥ����� channel ������礭������ overflow ���֤��ޤ���
--- Hist1#equiv
      �ҥ��ȥ����� equivalent event �ο����֤��ޤ�
      ��overflow��underflow �Ͻ����ˡ�
--- Hist1#err2a
--- Hist1#unpack_err
      �ҥ��ȥ����γ� channel �θ�������Ȥ����֤��ޤ���
--- Hist1#error(xch)
      ((|xch|)) ���ܤ� channel �θ����֤��ޤ���
--- Hist1#fit(par, func[, option])
--- Hist1#fit(par[, option]) { ... }
      �ҥ��ȥ�����ؿ� ((|func|)) �� fit ������̤Υѥ�᡼����
      ���θ����ڤӦ�����ͤ��֤��ޤ�����1���� ((|par|)) �ˤ�
      ����ѥ�᡼����Ϳ���ޤ���fitting �ؿ� ((|func|)) �� Proc ���֥������Ȥ�
      �ʲ���ʸ����Τ����줫�Ǥ���
      * "G" Gauss ʬ��
      * "E" exponential
      * "P((|n|))" ((|n|))��¿�༰
      �ޤ��֥�å���Ϳ���뤳�Ȥ����ޤ���
--- Hist1#mean
      �ҥ��ȥ�����ʿ���ͤ��֤��ޤ�
      ��overflow��underflow �Ͻ����ˡ�
--- Hist1#overflow
      �ҥ��ȥ����ξ�¤���礭������ȥ꡼�ι�פ��֤��ޤ���
--- Hist1#pack(ary)
      �ҥ��ȥ����γ� channel ����Ȥ����� ((|ary|)) ����Ȥ��֤������ޤ���
--- Hist1#pack_err(ary)
      �ҥ��ȥ����γ� channel �θ������� ((|ary|)) ����Ȥ��֤������ޤ���
--- Hist1#random
      �ҥ��ȥ������Ψʬ�ۤȤ���������֤��ޤ���
--- Hist1#sigma
      �ҥ��ȥ�����ɸ���к����֤��ޤ�
      ��overflow��underflow �Ͻ����ˡ�
--- Hist1#to_a
--- Hist1#unpack
      �ҥ��ȥ����γ� channel ����Ȥ�����Ȥ����֤��ޤ���
--- Hist1#underflow
      �ҥ��ȥ����β��¤�꾮��������ȥ꡼�ι�פ��֤��ޤ���


= Hist2

2�����ҥ��ȥ���९�饹��

== �����ѡ����饹:

* ((<BasicHist>))

== ���饹�᥽�å�:

--- Hist2.new(id, title, xbin, xmin, xmax, ybin, ymin, ymax)
      ID ((|id|))�������ȥ� ((|title|))��x �� y �����Υ����ͥ����
      ���¡���¤����줾�� ((|xbin|))��((|xmin|))��((|xmax|)) �� 
      ((|ybin|))��((|ymin|))��((|ymax|)) �����ֳ� bin ��
      2�����ҥ��ȥ������֤��ޤ���
--- Hist2.read(id, filename)
      �ե����� ((|filename|)) ���� ID ((|id|)) ��2�����ҥ��ȥ����
      ���ɤ߽Ф����֤��ޤ����ե����� ((|filename|)) ��¸�ߤ��ʤ�����
      �㳰��ȯ�����ޤ����ե����� ((|filename|)) ��� 
      ID ((|id|)) �Υҥ��ȥ���ब¸�ߤ��ʤ����䡢
      ¸�ߤ��Ƥ�2�����ҥ��ȥ����Ǥʤ����� (({nil})) ���֤��ޤ���

== �᥽�å�:

--- Hist2#[](xch, ych)
--- Hist2#content(xch, ych)
      x��y �ˤĤ��Ƥ��줾�� ((|xch|)) ���ܡ�
      ((|ych|)) ���ܤ� channel ����Ȥ��֤��ޤ���
      ((|xch|))��((|ych|)) �� 0 �ʲ��ξ��� underflow ��
      �ҥ��ȥ����� channel ������礭������ overflow ���֤��ޤ���
--- Hist2#book_xproj
      �ҥ��ȥ�����°���롢X �������ؤ� projection �ҥ��ȥ������������ޤ���
      ��������book ���������Ǥϲ��� fill ����ޤ���
      2�����ҥ��ȥ����� fill ����ȡ���ưŪ�ˤ����°����
      projection �ҥ��ȥ����ˤ� fill ����ޤ���
--- Hist2#book_yproj
      �ҥ��ȥ�����°���롢Y �������ؤ� projection �ҥ��ȥ������������ޤ���
--- Hist2#book_xband(min, max)
      y ���ͤ� ((|min|)) �� ((|max|)) �δ֤����˸��ꤷ����
      band ���� X �������ؤ� projection �ҥ��ȥ������������ޤ���
--- Hist2#book_yband(min, max)
      x ���ͤ� ((|min|)) �� ((|max|)) �δ֤����˸��ꤷ����
      band ���� Y �������ؤ� projection �ҥ��ȥ������������ޤ���
--- Hist2#book_xslice(num)
      2�����ҥ��ȥ����� ((|num|)) �Ĥ� slice ����
      band ���� X �������ؤ� projection �ҥ��ȥ������������ޤ���
--- Hist2#book_yslice(num)
      2�����ҥ��ȥ����� ((|num|)) �Ĥ� slice ����
      band ���� Y �������ؤ� projection �ҥ��ȥ������������ޤ���
--- Hist2#err2a([option[, num]])
--- Hist2#unpack_err([option[, num]])
      ((|option|)) �� (({"HIST"})) ����ꤷ����硢
      ���뤤�Ͼ�ά�������ϡ��ҥ��ȥ����γ� channel �θ���
      �󼡸�����Ȥ����֤��ޤ���
      (({"PROX"}))��(({"PROY"}))��(({"BANX"}))��
      (({"BANY"}))��(({"SLIX"}))��(({"SLIY"}))
      ����ꤷ�����ϡ����줾�� x ���� y �������ؤ� projection��
      band��slice �ҥ��ȥ����θ�������ˤ����֤��ޤ���
      Hist2 ���饹�Υ��󥹥��� (({hist2})) ���Ф��ơ�
      (({hist2.err2a[2][4]})) �� (({hist2.error(5, 3)})) ��
      Ʊ����̤ˤʤ�ޤ��ʤ����������ˡ�
--- Hist2#error(xch, ych)
      x��y �ˤĤ��Ƥ��줾�� ((|xch|)) ���ܡ�
      ((|ych|)) ���ܤ� channel �θ����֤��ޤ���
--- Hist2#fill(x, y[, inc])
      �� (((|x|)), ((|y|))) ���б����� bin �� ((|inc|)) ����
      ���䤷�ޤ���((|inc|)) �Υǥե�����ͤ� 1 �Ǥ���
--- Hist2#fill(ary)
      �ҥ��ȥ����γ� channel ���󼡸����� ((|ary|)) ����Ȥ�ʬ����
      ���䤷�ޤ���
--- Hist2#pack(ary)
      �ҥ��ȥ�������Ȥ��󼡸����� ((|ary|)) ����Ȥ��֤������ޤ���
--- Hist2#pack_err(ary)
      �ҥ��ȥ����θ����󼡸����� ((|ary|)) ����Ȥ��֤������ޤ���
--- Hist2#random
      �ҥ��ȥ������Ψʬ�ۤȤ����󼡸���������֤��ޤ���
--- Hist2#to_a([option[, num]])
--- Hist2#unpack([option[, num]])
      ((|option|)) �� (({"HIST"})) ����ꤷ����硢
      ���뤤�Ͼ�ά�������ϥҥ��ȥ����γ� channel ����Ȥ�
      �󼡸�����Ȥ����֤��ޤ���
      (({"PROX"}))��(({"PROY"}))��(({"BANX"}))��
      (({"BANY"}))��(({"SLIX"}))��(({"SLIY"}))
      ����ꤷ�����ϡ����줾�� x ���� y �������ؤ� projection��
      band��slice �ҥ��ȥ�������Ȥ�����ˤ����֤��ޤ���
      Hist2 ���饹�Υ��󥹥��� (({hist2})) ���Ф��ơ�
      (({hist2.to_a[2][4]})) �� (({hist2.contents(5, 3)})) ��
      Ʊ����̤ˤʤ�ޤ��ʤ����������ˡ�
--- Hist2#xproj(id, title)
      �ҥ��ȥ����� X �������� project ������̤�1�����ҥ��ȥ�����
      �֤��ޤ���(({((<Hist2#book_xproj>))})) �Ȥϰ㤤��
      ID ((|id|))�������ȥ� ((|title|)) �ο�����
      1�����ҥ��ȥ�����������������򡢤��λ����Ǥ�
      2�����ҥ��ȥ�������Ȥ� fill ���ޤ���
--- Hist2#yproj(id, title)
      �ҥ��ȥ����� Y �������� project ������̤�1�����ҥ��ȥ�����
      �֤��ޤ���


= Profile

�ץ�ե�����ҥ��ȥ���९�饹��

== �����ѡ����饹:

* ((<BasicHist>))

== ���饹�᥽�å�:

--- Profile.new(id, title, xbin, xmin, xmax, ymin, ymax[, option])
      ID ((|id|))�������ȥ� ((|title|))�������ͥ��
      ((|xbin|))��x �� y �����β��¡���¤����줾�� 
      ((|xmin|))��((|xmax|)) �� ((|ymin|))��((|ymax|))
      �����ֳ� bin �Υץ�ե�����ҥ��ȥ������֤��ޤ���
--- Profile.read(id, filename)
      �ե����� ((|filename|)) ���� ID ((|id|))
      �Υץ�ե�����ҥ��ȥ������ɤ߽Ф����֤��ޤ���
      �ե����� ((|filename|)) ��¸�ߤ��ʤ�����
      �㳰��ȯ�����ޤ����ե����� ((|filename|)) ��� 
      ID ((|id|)) �Υҥ��ȥ���ब¸�ߤ��ʤ����䡢
      ¸�ߤ��Ƥ�ץ�ե�����ҥ��ȥ����Ǥʤ����� (({nil})) ���֤��ޤ���

== �᥽�å�:

--- Profile#[](xch)
--- Profile#content(xch)
      ((|xch|)) ���ܤ� channel ����Ȥ��֤��ޤ���
      ((|xch|)) �� 0 �ʲ��ξ��� underflow ��
      �ҥ��ȥ����� channel ������礭������ overflow ���֤��ޤ���
--- Profile#err2a
--- Profile#unpack_err
      �ҥ��ȥ����γ� channel �θ�������Ȥ����֤��ޤ���
--- Profile#error(xch)
      ((|xch|)) ���ܤ� channel �θ����֤��ޤ���
--- Profile#fill(x, y[, inc])
      �� (((|x|)), ((|y|))) ���б����� bin �� ((|inc|)) ����
      ���䤷�ޤ���((|inc|)) �Υǥե�����ͤ� 1 �Ǥ���
--- Profile#fit(par, func[, option])
--- Profile#fit(par[, option]) { ... }
      �ҥ��ȥ�����ؿ� ((|func|)) �� fit ������̤Υѥ�᡼����
      ���θ����ڤӦ�����ͤ��֤��ޤ����ư����ΰ�̣��
      (({((<Hist1#fit>))})) �Τ�Τ�Ʊ���Ǥ���
--- Profile#to_a
--- Profile#unpack
      �ҥ��ȥ����γ� channel ����Ȥ�����Ȥ����֤��ޤ���


= Ntuple

Row-Wise N-tuple �� Column-Wise N-tuple �οƤȤʤ���ݥ��饹��

== �����ѡ����饹:

* Data

== ���󥯥롼�ɤ��Ƥ���⥸�塼��:

* Enumerable

== �᥽�å�:

--- Ntuple#delete
      N-tuple �����夫�������ޤ���
      ������줿 N-tuple �˥����������褦�Ȥ�����㳰��ȯ�����ޤ���
--- Ntuple#deleted?
      N-tuple ���������Ƥ����翿���֤��ޤ���
--- Ntuple#entry
--- Ntuple#length
--- Ntuple#size
      N-tuple �Υ��٥�ȤΥ���ȥ꡼�����֤��ޤ���
--- Ntuple#ntuple_id
      N-tuple �� ID ���֤��ޤ���
--- Ntuple#reset([title])
      N-tuple ��ꥻ�åȤ��ޤ���
      ���� ((|title|)) ��Ϳ����줿���ϥ����ȥ���ѹ����ޤ���
--- Ntuple#title
      N-tuple �Υ����ȥ��ʸ����Ȥ����֤��ޤ���


= RWNtuple

Row-Wise N-tuple ���饹��

== �����ѡ����饹:

* ((<Ntuple>))

== ���饹�᥽�å�:

--- RWNtuple.new(id, title, dir, memory, member1, ...)
      ID ((|id|))�������ȥ� ((|title|)) �� Row-Wise N-tuple ��
      �ǥ��쥯�ȥ� ((|dir|)) ������������֤��ޤ���

== �᥽�å�:

--- RWNtuple#[](event)
--- RWNtuple#get_event(event)
      ((|event|)) ���ܤΥ��٥�Ȥ�ϥå���ˤ����֤��ޤ���
--- RWNtuple#<<(data)
--- RWNtuple#fill(data)
      �ϥå���Ȥ����Ϥ��줿���٥�ȥǡ��� ((|data|)) ��
      N-tuple �� fill ���ޤ���
--- RWNtuple#copy(id[, title])
      Ʊ�����С�����ä���ID ((|id|)) �� N-tuple �����������֤��ޤ���
      ���٥�ȥ���ȥ꡼�ϥ��ԡ�����ޤ���
      ���� ((|title|)) ��Ϳ����줿���ϥ����ȥ�򤽤�����ꤷ�ޤ���
--- RWNtuple#each { |var| ... }
      N-tuple �γƥ��٥�ȤΥǡ����ǥ֥�å���ɾ�����ޤ���
--- RWNtuple#fill_hist1(member, hist[, from, to])
--- RWNtuple#fill_hist1(member, hist[, from, to]) { ... }
      1�����ҥ��ȥ���� ((|hist|)) ��
      N-tuple �Υ��٥���ֹ� ((|from|)) ���� ((|to|)) �ޤǤ�
      ���С� ((|member|)) ���ͤ� fill ���ޤ���
      �֥�å���Ϳ�����Ƥ������
      fill ����ݤνŤߴؿ��Ȥ��Ƥ�����Ѥ��ޤ���
      ñ�ˤ�����С����ͤ򤽤Τޤ� fill ��������ʤ�С�
      (({((<Ntuple#projection>))})) ��Ȥ����⤳�������������Ū�˹�®�Ǥ���
--- RWNtuple#fill_hist2(xmember, ymember, hist[, from, to])
--- RWNtuple#fill_hist2(xmember, ymember, hist[, from, to]) { ... }
      2�����ҥ��ȥ���� ((|hist|)) ��
      N-tuple �Υ��٥���ֹ� ((|from|)) ���� ((|to|)) �ޤǤ�
      ���С� ((|xmember|))��((|ymember|)) ���ͤ��Ȥ� fill ���ޤ���
      ���� ((|func|)) ��֥�å���Ϳ�����Ƥ������
      fill ����ݤνŤߴؿ��Ȥ��Ƥ�����Ѥ��ޤ���
--- RWNtuple#max(member)
      N-tuple �Υ��С� ((|member|)) �κ����ͤ��֤��ޤ�
--- RWNtuple#members
      N-tuple �γƥ��С�̾������ˤ����֤��ޤ���
--- RWNtuple#min(member)
      N-tuple �Υ��С� ((|member|)) �κǾ��ͤ��֤��ޤ�
--- RWNtuple#projection(hist) { ... }
      N-tuple ��1���٥��ʬ���Ǽ�����ϥå��������Ȥ��ƥ֥�å���
      ɾ���������η�̤�ҥ��ȥ���� ((|hist|)) �� fill ���ޤ���
      2���������ץ�ե�����ҥ��ȥ����� fill ������ϡ�
      �֥�å��� (({[ x, y ]})) �η���������֤�ɬ�פ�����ޤ���
      �֥�å��� (({nil})) ���֤������٥�Ȥ� fill ����ޤ���


= CWNtuple

Column-Wise N-tuple ���饹��
���٥�ȥ֥�å����饹 ((<CWNBlock>)) �ȷ�ӤĤ��ƻȤ��ޤ���
  rzfile = CERN::HBook2::RZFile.open("test.rz", "topdir", "N")
  cwntuple = CERN::HBook2::CWNtuple.new(10, "CWNtuple", rzfile)
  EventBlk = CERN::HBook2::CWNBlock.new("EventBlk", "x:r", "y:r", "n:i")
  cwntuple.set_block EventBlk
  block = EventBlk.new
  block.x = 1.5
  block.y = 3.6
  block.n = 100
  cwntuple << block
�⤷����
  rzfile = CERN::HBook2::RZFile.open("test.rz", "topdir", "N")
  cwntuple = CERN::HBook2::CWNtuple.new(10, "CWNtuple", rzfile)
  EventBlk = CERN::HBook2::CWNBlock.new("EventBlk", "x:r", "y:r", "n:i")
  cwntuple.set_block EventBlk
  EventBlk.x = 1.5
  EventBlk.y = 3.6
  EventBlk.z = 100
  cwntuple.fill_all

== �����ѡ����饹:

* ((<Ntuple>))

== ���饹�᥽�å�:

--- CWNtuple.new(id, title, dir)
      ID ((|id|))�������ȥ� ((|title|)) �� Coulmn-Wise N-tuple ��
      �ǥ��쥯�ȥ� ((|dir|)) ������������֤��ޤ���

== �᥽�å�:

--- CWNtuple#[](event)
--- CWNtuple#get_event(event[, block])
      ((|event|)) ���ܤΥ��٥�Ȥ򥤥٥�ȥ֥�å�������ˤ����֤��ޤ���      
      ���٥�ȥ֥�å����饹 ((|block|)) ��Ϳ����줿����
      ���Υ��٥�ȥ֥�å��Υ��٥�Ȥ������֤��ޤ���
--- CWNtuple#<<(data)
--- CWNtuple#fill(data)
      ���٥�ȥ֥�å� ((|data|)) �ˤޤȤ��줿�ǡ�����
      N-tuple �� fill ���ޤ���
--- CWNtuple#each { ... }
      �ƥ��٥�ȤˤĤ��ƥ��٥�ȥ֥�å�������ǥ֥�å���ɾ�����ޤ���
--- CWNtuple#fill_all
      N-tuple �˷�ӤĤ���줿���ƤΥ��٥�ȥ֥�å��ˤޤȤ��줿�ǡ�����
      N-tuple �� fill ���ޤ���
--- CWNtuple#blocks
      N-tuple �˷�ӤĤ����Ƥ���֥�å�������ˤ����֤��ޤ���
--- CWNtuple#set_block(block)
      ���٥�ȥ֥�å����饹 ((|block|)) �� N-tuple �˷�ӤĤ��ޤ���


= CWNBlock

Column-wise N-tuple �� fill ���륤�٥�Ȥ�ޤȤ᤿
��¤�Ρʥ֥�å��˥��饹��
Struct �Τ褦�ˡ�((<CWNBlock.new>)) �᥽�åɤˤ��
��ʬ�λҥ��饹�򿷤����������ޤ���

== �����ѡ����饹:

* Data

== ���󥯥롼�ɤ��Ƥ���⥸�塼��:

* Enumerable

== ���饹�᥽�å�:

--- CWNBlock.new(name, member1, member2, ...)
      ̾�� ((|name|)) �� ���٥�ȥ֥�å����饹��
      ���������֤��ޤ���

== �᥽�å�:

--- CWNBlock#members
      ���٥�ȥ֥�å��Υ��С�̾������ˤ����֤��ޤ���
--- CWNBlock#each { ... }
      ���٥�ȥ֥�å��γƥ��С����ͤǥ֥�å���ɾ�����ޤ���
--- CWNBlock#length
--- CWNBlock#size
      ���٥�ȥ֥�å��Υ��С��ο����֤��ޤ���
--- CWNBlock#to_a
--- CWNBlock#values
      ���٥�ȥ֥�å��γƥ��С����ͤ�����ˤ����֤��ޤ���


= RZDir

HBOOK directory stream ���饹��

== �����ѡ����饹:

* Data

== ���󥯥롼�ɤ��Ƥ���⥸�塼��:

* Enumerable

== ���饹�᥽�å�:

--- RZDir.new([dir])
--- RZDir.open([dir])
--- RZDir.open([dir]) { |rzdir| ... }
      �ǥ��쥯�ȥ�̾ ((|dir|)) �Υǥ��쥯�ȥꥹ�ȥ꡼��򳫤��ޤ���
      ���� ((|dir|)) �Υǥե�����ͤϥ����ȥǥ��쥯�ȥ�Ǥ���
      open() �ϥ֥�å�����ꤹ�뤳�Ȥ��Ǥ������ξ��ϡ�
      �ǥ��쥯�ȥꥹ�ȥ꡼�������ˤ��ƥ֥�å���ɾ������
      ���η�̤��֤��ޤ���
      �֥�å��μ¹Ԥ���λ����ȡ��ǥ��쥯�ȥ�ϼ�ưŪ�˥���������ޤ���
--- RZDir.chdir(dir)
      �����ȥǥ��쥯�ȥ�� ((|dir|)) ���ѹ����ޤ���
--- RZDir.delete(dir)
--- RZDir.rmdir(dir)
      ((|dir|)) �Ȥ����ǥ��쥯�ȥ�������ޤ���
--- RZDir.entries(dir)
      �ǥ��쥯�ȥ� ((|dir|)) �������Ǥ�����ˤ����֤��ޤ���
--- RZDir.expand_path(dir)
      �ǥ��쥯�ȥ� ((|dir|)) �Υե�ѥ�̾���֤��ޤ���
--- RZDir.foreach(dir) { |item| ... }
      �ǥ��쥯�ȥ� ((|dir|)) �γ����Ǥ��Ф��ƥ֥�å���ɾ�����ޤ���
--- RZDir.list([dir])
      �ǥ��쥯�ȥ� ((|dir|)) �������ǤΥꥹ�Ȥ�ɸ����Ϥ˽��Ϥ��ޤ���
      ((|dir|)) �Υǥե�����ͤϥ����ȥǥ��쥯�ȥ�Ǥ���
--- RZDir.getwd
--- RZDir.pwd
      �����ȥǥ��쥯�ȥ�Υե�ѥ�̾���֤��ޤ���
--- RZDir.mkdir(dir)
      ((|dir|)) �Ȥ����������ǥ��쥯�ȥ���äơ�
      ���Υǥ��쥯�ȥꥹ�ȥ꡼����֤��ޤ���

== �᥽�å�:

--- RZDir#[](id)
      �ǥ��쥯�ȥ���ˤ��� ID ((|id|)) �Υҥ��ȥ�������� N-tuple ���֤��ޤ���
--- RZDir#<<(hist)
--- RZDir#write(hist)
      �ҥ��ȥ���� ((|hist|)) ��ǥ��쥯�ȥ�˽񤭹��ߤޤ���
      �ǥ��쥯�ȥ�ϥե������Τ�ΤǤʤ���Фʤ�ޤ���
--- RZDir#close
      �ǥ��쥯�ȥꥹ�ȥ꡼����Ĥ��ޤ����Ĥ�����ˤ��Υǥ��쥯�ȥ��
      �����������褦�Ȥ�����㳰��ȯ�����ޤ���
--- RZDir#closed?
      �ǥ��쥯�ȥꥹ�ȥ꡼�ब���Ǥ��Ĥ��Ƥ������ (({true})) ���֤��ޤ���
--- RZDir#each { |item| ... }
      �ǥ��쥯�ȥꥹ�ȥ꡼��γ����Ǥ��Ф��ƥ֥�å���ɾ�����ޤ���
--- RZDir#read
      �ǥ��쥯�ȥꥹ�ȥ꡼�फ�鼡�����Ǥ��֤��ޤ���
--- RZDir#rewind
      �ǥ��쥯�ȥꥹ�ȥ꡼����ɤ߹��߰��֤���Ƭ���ᤷ�ޤ���
--- RZDir#to_s
      �ǥ��쥯�ȥ�ѥ���ʸ����Ȥ����֤��ޤ���
--- RZDir#write_all
      ���������ҥ��ȥ������� N-tuple ��ǥ��쥯�ȥ�˽񤭹��ߤޤ���
      �ǥ��쥯�ȥ�ϥե������Τ�ΤǤʤ���Фʤ�ޤ���


= RZFile

RZ file ���饹��

== �����ѡ����饹:

* ((<RZDir>))

== ���饹�᥽�å�:

--- RZFile.new(filename[, topdir[, option]])
--- RZFile.open(filename[, topdir[, option]])
--- RZFile.open(filename[, topdir[, option]]) { |rzfile| ... }
      �ե�����̾ ((|filename|)) �� RZ file �� open ���ơ�
      �ǥ��쥯�ȥ�̾ ((|topdir|)) �Ȥ��ƥޥ���Ȥ���
      ���Υǥ��쥯�ȥꥹ�ȥ꡼����֤��ޤ���
      ((|topdir|)) ����ά���줿���ϡ�
      lun1��lun2���ġ��Τ褦��Ŭ���˷����ޤ���
      open() �ϥ֥�å�����ꤹ�뤳�Ȥ��Ǥ������ξ��ϡ�
      ������ RZ file �Υǥ��쥯�ȥꥹ�ȥ꡼�������ˤ���
      �֥�å���ɾ���������η�̤��֤��ޤ���
      �֥�å��μ¹Ԥ���λ����ȡ�RZ file �ϼ�ưŪ�˥���������ޤ���

== �᥽�å�:

--- RZFile#close
      RZ file ���Ĥ��ޤ����Ĥ�����ˤ��� RZ file �˥����������褦�Ȥ����
      �㳰��ȯ�����ޤ���
--- RZFile#filename
      �ե�����̾���֤��ޤ���
--- RZFile#lun
      �ե������ֹ���֤��ޤ���
--- RZFile#option
      �����Ȥ��˥��ץ����Ȥ����Ϥ���ʸ������֤��ޤ���
--- RZFile#topname
      �ȥåץǥ��쥯�ȥ�̾���֤��ޤ���

=end
