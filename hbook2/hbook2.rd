=begin RD

= HBook2 extension library

HBook2 is a histogram library using the CERNLIB HBOOK package.
Some histogram classes, N-tuple classes, a directory stream class and so on
are defined under CERN::HBook2 module.


= HBook2

Histogram module using the CERNLIB HBOOK package.

== module function:

--- HBook2.exist?(id)
      returns true if a histogram with ID ((|id|)) exists on memory.
--- HBook2.merge(srces, dest)
      reads files give with an array ((|srces|)), merges the histograms
      and N-tuples, and writes them to a new file ((|dest|)).
--- HBook2.read_all(filename)
      reads a file ((|filename|)) and returns each array of objects of
      ((<Hist1>)), ((<Hist2>)), ((<Profile>)) and ((<Ntuple>)) class.
      If a file ((|filename|)) does not exist, an exception occurs.
--- HBook2.write_all(filename)
      writs all histograms on memory to a file ((|filename|)).


= BasicHist

Virtual class to be a parent of histogram classes.

== super class:

* Data

== method:

--- BasicHist#+(other)
--- BasicHist#-(other)
--- BasicHist#*(other)
--- BasicHist#/(other)
      performs the operation with each channel of the histogram,
      and returns the result as a histogram.
      The ID of the returned histogram is determined automatically,
      so user usually has to specify it explicitly
      with (({((<BasicHist#id=>))})) method.
--- BasicHist#copy(id[, title])
      copies the histogram to a new histogram with ID ((|id|)).
      If ((|title|)) is given, the title of the new histogram is set to it.
--- BasicHist#delete
      deletes the histogram from memory.
      If user accesses the deleted histogram, exception is raised.
--- BasicHist#deleted?
      returns true if the histogram is already deleted.
--- BasicHist#entry
      returns the number of entry in the histogram.
--- BasicHist#hist_id
      returns the ID number of the histogram.
--- BasicHist#hist_id=(id)
      sets the ID number to ((|id|)).
--- BasicHist#max
      returns the maximum contents of the histogram
      (except for overflow and underflow).
--- BasicHist#min
      returns the minimum contents of the histogram
      (except for overflow and underflow).
--- BasicHist#reset([title])
      resets all channels to 0.
      If ((|title|)) is given, the title is also changed.
--- BasicHist#sum
      returns the sum of the contents of all channels.
      (except for overflow and underflow).
--- BasicHist#title
      returns the title of the histogram.
--- BasicHist#write(filename)
      writes the histogram to a file ((|filename|)).


= Hist1

1-dimensional histogram class.

== super class:

* ((<BasicHist>))

== class methods:

--- Hist1.new(id, title, bin, min, max)
      returns a new one-dimensional histogram with ID of ((|id|)),
      title ((|title|)), equidistant bins of ((|bin|)) channels
      from ((|min|)) to ((|max|)).
--- Hist1.func(id, title, bin, min, max, func)
--- Hist1.func(id, title, bin, min, max) { ... }
      creates a new one-dimensional histogram with ID of ((|id|)),
      title ((|title|)), equidistant bins of ((|bin|)) channels
      from ((|min|)) to ((|max|)), and fills it with values obtained from
      a function ((|func|)) or block.
--- Hist1.read(id, filename)
      reads a one-dimensional histogram with ID of ((|id|))
      from a file ((|filename|)).
      If a file ((|filename|)) does not exists, exception is raised.
      If a histogram with ID of ((|id|)) does not exist
      in a file ((|filename|)) or is not one-dimensional,
      returns (({nil})).


== methods:

--- Hist1#<<(x)
--- Hist1#fill(x[, inc])
      increments by ((|inc|)) the channel containing the value ((|x|)).
      The default value of ((|inc|)) is 1.
      Or, in case of ((|x|)) being an array, increments each channel
      by the contents of the array.
--- Hist1#[](xch)
--- Hist1#content(xch)
      returns the contents of ((|xch|))-th channel,
      underflow if ((|xch|)) is less than 0,
      or overflow if ((|xch|)) is more than the number of channels.
--- Hist1#equiv
      returns the number of equivalent events
      (except for overflow and underflow).
--- Hist1#err2a
--- Hist1#unpack_err
      returns an array containing the error of each channel.
--- Hist1#error(xch)
      returns the error of ((|xch|))-th channel.
--- Hist1#fit(par, func[, option])
--- Hist1#fit(par[, option]) { ... }
      fits the histogram with a function ((|func|)) or block,
      and returns the obtained fitting parameters, their errors
      and chi-squared value.
      Initial parameters must be given as the first argument ((|par|)).
      The fitting function ((|func|)) is a Proc object or
      either of the string below:
      * "G" Gaussian
      * "E" exponential
      * "P((|n|))" ((|n|)) polynomial
--- Hist1#mean
      returns mean value of the histogram
      (except for overflow and underflow).
--- Hist1#overflow
      returns the entry of overflow of the histogram.
--- Hist1#pack(ary)
      replaces the content of each channel from the contents
      of an array ((|ary|)).
--- Hist1#pack_err(ary)
      replaces the error of each channel from the contents
      of an array ((|ary|)).
--- Hist1#random
      returns random number distributed according to the contents
      of the histogram.
--- Hist1#sigma
      returns the standard deviation of the histogram
      (except for overflow and underflow).
--- Hist1#to_a
--- Hist1#unpack
      returns an array containing the content of each channel.
--- Hist1#underflow
      returns the entry of underflow of the histogram.


= Hist2

2-dimensional histogram class.

== super class:

* ((<BasicHist>))

== class methods:

--- Hist2.new(id, title, xbin, xmin, xmax, ybin, ymin, ymax)
      returns a new 2-dimensional histogram with ID of ((|id|)),
      title ((|title|)), equidistant bins of ((|xbin|)) channels
      from ((|xmin|)) to ((|xmax|)) for X-axis,
      and equidistant bins of ((|ybin|)) channels
      from ((|ymin|)) to ((|ymax|)) for Y-axis.
--- Hist2.read(id, filename)
      reads a 2-dimensional histogram with ID of ((|id|))
      from a file ((|filename|)).
      If a file ((|filename|)) does not exists, exception is raised.
      If a histogram with ID of ((|id|)) does not exist
      in a file ((|filename|)) or is not 2-dimensional,
      returns (({nil})).

== methods:

--- Hist2#[](xch, ych)
--- Hist2#content(xch, ych)
      returns the content of the specified bin, ((|xch|))-th for X
      and ((|ych|))-th for Y-axis,
      underflow if ((|xch|)) or ((|ych|)) is less then 0,
      or overflow if ((|xch|)) or ((|ych|)) is more than the number
      of channels.
--- Hist2#book_xproj
      books a projection of the histogram onto X.
      It does NOT be filled at the time it is booked.
      When the 2-dimensional histogram is filled,
      its projections are also filled automatically.
--- Hist2#book_yproj
      books a projection of the histogram onto Y.
--- Hist2#book_xband(min, max)
      books a projection of the histogram onto X,
      restricted to the Y interval (((|min|)), ((|max|))).
--- Hist2#book_yband(min, max)
      books a projection of the histogram onto Y,
      restricted to the X interval (((|min|)), ((|max|))).
--- Hist2#book_xslice(num)
      books slices along Y of the histogram as ((|num|)) 1-dimensional
      histograms.
--- Hist2#book_yslice(num)
      books slices along X of the histogram as ((|num|)) 1-dimensional
      histograms.
--- Hist2#err2a([option[, num]])
--- Hist2#unpack_err([option[, num]])
      In case ((|option|)) is (({"HIST"})) or not given,
      returns a 2-dimensional array containing the error of each channel
      of the 2-dimensional histogram.
      In case (({"PROX"})), (({"PROY"})), (({"BANX"})),
      (({"BANY"})), (({"SLIX"})) or (({"SLIY"})) is specified,
      returns an array of containing the error of projection onto X or Y,
      band, or slice, respectively.
      For (({hist2})) being an instance of ((<Hist2>)) class,
      (({hist2.err2a[2][4]})) gives the same result as (but is slower than)
      (({hist2.error(5, 3)})).
--- Hist2#error(xch, ych)
      returns the error of the specified bin, ((|xch|))-th for X
      and ((|ych|))-th for Y-axis,
--- Hist2#fill(x, y[, inc])
      increments by ((|inc|)) the channel containing the pair of value
      (((|x|)), ((|y|))).
      The default value of ((|inc|)) is 1.
--- Hist2#fill(ary)
      increments each channel by the contents of a 2-dimensional array
      ((|ary|)).

--- Hist2#pack(ary)
      replaces the content of each channel from the contents
      of a 2-dimensional array ((|ary|)).
--- Hist2#pack_err(ary)
      replaces the error of each channel from the contents
      of a 2-dimensional array ((|ary|)).
--- Hist2#random
      returns a pair of random numbers distributed according to the contents
      of the histogram.
--- Hist2#to_a([option[, num]])
--- Hist2#unpack([option[, num]])
      In case ((|option|)) is (({"HIST"})) or not given,
      returns a 2-dimensional array containing the content of each channel
      of the 2-dimensional histogram.
      In case (({"PROX"})), (({"PROY"})), (({"BANX"})),
      (({"BANY"})), (({"SLIX"})) or (({"SLIY"})) is specified,
      returns an array of containing the content of projection onto X or Y,
      band, or slice, respectively.
      For (({hist2})) being an instance of ((<Hist2>)) class,
      (({hist2.to_a[2][4]})) gives the same result as (but is slower than)
      (({hist2.contents(5, 3)})).
--- Hist2#xproj(id, title)
      returns a projection onto X of the 2-dimensional histogram.
      Different from (({((<Hist2#book_xproj>))})),
      books a new 1-dimensional histogram with ID of ((|id|)),
      title ((|title|)), and fills it with the contents of
      the 2-dimensional histogram.
--- Hist2#yproj(id, title)
      returns a projection onto Y of the 2-dimensional histogram.


= Profile

Profile histogram class.

== super class:

* ((<BasicHist>))

== class methods:

--- Profile.new(id, title, xbin, xmin, xmax, ymin, ymax[, option])
      returns a new profile histogram with ID of ((|id|)),
      title ((|title|)), equidistant bins of ((|xbin|)) channels
      from ((|xmin|)) to ((|xmax|)) for X-axis,
      restricted to Y from ((|ymin|)) to ((|ymax|)).
--- Profile.read(id, filename)
      reads a profile histogram with ID of ((|id|))
      from a file ((|filename|)).
      If a file ((|filename|)) does not exists, exception is raised.
      If a histogram with ID of ((|id|)) does not exist
      in a file ((|filename|)) or is not a profile histogram,
      returns (({nil})).

--- Profile.new(id, title, xbin, xmin, xmax, ymin, ymax[, option])
--- Profile.read(id, filename)

== methods:

--- Profile#[](xch)
--- Profile#content(xch)
      returns the content of ((|xch|))-th channel.
--- Profile#err2a
--- Profile#unpack_err
      returns an array containing the error of each channel.
--- Profile#error(xch)
      returns the error of ((|xch|))-th channel.
--- Profile#fill(x, y[, inc])
      increments by ((|inc|)) the channel containing the pair of value
      (((|x|)), ((|y|))).
      The default value of ((|inc|)) is 1.
--- Profile#fit(par, func[, option])
--- Profile#fit(par[, option]) { ... }
      fits the histogram with a function ((|func|)) or block,
      and returns the obtained fitting parameters, their errors
      and chi-squared value.
      Initial parameters must be given as the first argument ((|par|)).
      The fitting function ((|func|)) is a Proc object or
      either of the string below:
      * "G" Gaussian
      * "E" exponential
      * "P((|n|))" ((|n|)) polynomial
--- Profile#to_a
--- Profile#unpack
      returns an array containing the content of each channel.


= Ntuple

Virtual class to be a parent of Row-Wise N-tuple and Column-Wise N-tuple.

== super class:

* Data

== including module:

* Enumerable

== methods:

--- Ntuple#delete
      deletes the N-tuple from memory.
      If user accesses the deleted N-tuple, an exception is raised.
--- Ntuple#deleted?
      returns true if the N-tuple is already deleted.
--- Ntuple#entry
--- Ntuple#length
--- Ntuple#size
      returns the number of events in the N-tuple.
--- Ntuple#ntuple_id
      returns the ID number of the N-tuple.
--- Ntuple#reset([title])
      resets the N-tuple.
      If ((|title|)) is given, the title is also changed.
--- Ntuple#title
      returns the title of the N-tuple.


= RWNtuple

Row-Wise N-tuple class.

== super class:

* ((<Ntuple>))

== class methods:

--- RWNtuple.new(id, title, dir, memory, member1, ...)
      returns a new Row-Wise N-tuple with ID of ((|id|)), title ((|title|)),
      booked on a directory ((|dir|)).

== methods:

--- RWNtuple#[](event)
--- RWNtuple#get_event(event)
      returns a hash containing ((|event|))-th event.
--- RWNtuple#<<(data)
--- RWNtuple#fill(data)
      fills the N-tuple with an event data ((|data|)), given as a hash.
--- RWNtuple#copy(id[, title])
      returns a new N-tuple with ID of ((|id|)), having same member
      as the N-tuple.
      The event entries are NOT copied.
      If ((|title|)) is given, the title of the new N-tuple is set to it.
--- RWNtuple#each { |var| ... }
      evaluates the block with each event data of the N-tuple.
--- RWNtuple#fill_hist1(member, hist[, from, to])
--- RWNtuple#fill_hist1(member, hist[, from, to]) { ... }
      fills a 1-dimensional-histogram ((|hist|)) with the values of
      member ((|member|)) from ((|from|))-th to ((|to|))-th event
      of the N-tuple.
      When a block is given, it is used as a weight function.
      This method is much faster than (({((<Ntuple#projection>))})).
--- RWNtuple#fill_hist2(xmember, ymember, hist[, from, to])
--- RWNtuple#fill_hist2(xmember, ymember, hist[, from, to]) { ... }
      fills a 2-dimensional-histogram ((|hist|)) with pairs of
      the values of member ((|xmember|)) and ((|ymember|))
      from ((|from|))-th to ((|to|))-th event of the N-tuple.
      When a block is given, it is used as a weight function.
--- RWNtuple#max(member)
      returns the maximum value of the member ((|member|)).
--- RWNtuple#members
      returns an array containing the name of each member of the N-tuple.
--- RWNtuple#min(member)
      returns the minimum value of the member ((|member|)).
--- RWNtuple#projection(hist) { ... }
      evaluates the block with hashes containing the event in the N-tuple,
      and fills a histogram ((|hist|)) with the results.
      To fill a 2-dimensional histogram or a profile,
      each call of the block must return an array containing (({[ x, y ]})).
      If the block returns (({nil})), the event is not filled.


= CWNtuple

Column-Wise N-tuple class.
It is used with event block class ((<CWNBlock>)), for example,
  rzfile = CERN::HBook2::RZFile.open("test.rz", "topdir", "N")
  cwntuple = CERN::HBook2::CWNtuple.new(10, "CWNtuple", rzfile)
  EventBlk = CERN::HBook2::CWNBlock.new("EventBlk", "x:r", "y:r", "n:i")
  cwntuple.set_block EventBlk
  block = EventBlk.new
  block.x = 1.5
  block.y = 3.6
  block.n = 100
  cwntuple << block
or
  rzfile = CERN::HBook2::RZFile.open("test.rz", "topdir", "N")
  cwntuple = CERN::HBook2::CWNtuple.new(10, "CWNtuple", rzfile)
  EventBlk = CERN::HBook2::CWNBlock.new("EventBlk", "x:r", "y:r", "n:i")
  cwntuple.set_block EventBlk
  EventBlk.x = 1.5
  EventBlk.y = 3.6
  EventBlk.z = 100
  cwntuple.fill_all

== super class:

* ((<Ntuple>))

== class methods:

--- CWNtuple.new(id, title, dir)
      returns a new Column-Wise N-tuple with ID of ((|id|)), title ((|title|)),
      booked on a directory ((|dir|)).

== methods:

--- CWNtuple#[](event)
--- CWNtuple#get_event(event[, block])
      returns an array containing the event blocks of ((|event|))-th event.
      If event block class ((|block|)) is given,
      returns only the event block.
--- CWNtuple#<<(data)
--- CWNtuple#fill(data)
      fills the N-tuple with an event block ((|data|)).
--- CWNtuple#each { ... }
      evaluates the block with an array containing the event blocks of
      each event of the N-tuple.
--- CWNtuple#fill_all
      fills the N-tuple with all data packed in the event blocks
      set to the N-tuple.
--- CWNtuple#blocks
      returns an array containing the event block classes set to the N-tuple. 
--- CWNtuple#set_block(block)
      sets an event block class ((|block|)) to the N-tuple.


= CWNBlock

Struct (block) class for events to fill Column-wise N-tuple.
It creates a new subclass by the ((<CWNBlock.new>)) method
like the builltin Struct class.

== super class:

* Data

== including module:

* Enumerable

== class methods:

--- CWNBlock.new(name, member1, member2, ...)
      returns a new event block class with a name of ((|name|)).

== methods:

--- CWNBlock#members
      returns an array containing the names of the members.
--- CWNBlock#each { ... }
      evaluates the block with the value of each member.
--- CWNBlock#length
--- CWNBlock#size
      returns the number of the members.
--- CWNBlock#to_a
--- CWNBlock#values
      returns an array containing the value of each member.


= RZDir

HBOOK directory stream class.

== super class:

* Data

== including module:

* Enumerable

== class methods:

--- RZDir.new([dir])
--- RZDir.open([dir])
--- RZDir.open([dir]) { |rzdir| ... }
      opens a directory stream of the directory ((|dir|)).
      The default directory is the current working directory.
      open() can be called with a block.
      If a block is given, evaluates the block with the directory stream,
      and returns the result.
      The directory stream is closed automatically.
--- RZDir.chdir(dir)
      sets the current working directory to ((|dir|)).
--- RZDir.delete(dir)
--- RZDir.rmdir(dir)
      removes the directory ((|dir|)).
--- RZDir.entries(dir)
      returns an array containing all histograms and N-tuples
      on the directory ((|dir|)).
--- RZDir.expand_path(dir)
      returns the full path name of the directory ((|dir|)).
--- RZDir.foreach(dir) { |item| ... }
      evaluates the block with each content of the directory ((|dir|)).
--- RZDir.list([dir])
      prints a list of contents of the directory ((|dir|)) to stdout.
      The default directory if the current working directory.
--- RZDir.getwd
--- RZDir.pwd
      returns the full path name of the current working directory.
--- RZDir.mkdir(dir)
      create a new directory ((|dir|)), and returns its directory stream.

== methods:

--- RZDir#[](id)
      returns a histogram or a N-tuple with ID of ((|id|)) on the directory.
--- RZDir#<<(hist)
--- RZDir#write(hist)
      write a histogram or a N-tuple ((|hist|)) to the directory.
      The directory must be on a file.
--- RZDir#close
      closes the directory stream.
      If user accesses the closed directory stream, an exception is raised.
--- RZDir#closed?
      returns true if the directory stream is already closed.
--- RZDir#each { |item| ... }
      evaluates the block with each content of the directory.
--- RZDir#read
      returns the next content in the directory stream.
--- RZDir#rewind
      reset the reading position of the directory stream to the head.
--- RZDir#to_s
      returns the path of the directory.
--- RZDir#write_all
      writes all histograms and N-tuples on memory to the directory.
      The directory must be on a file.


= RZFile

RZ file class.

== super class:

* ((<RZDir>))

== class methods:

--- RZFile.new(filename[, topdir[, option]])
--- RZFile.open(filename[, topdir[, option]])
--- RZFile.open(filename[, topdir[, option]]) { |rzfile| ... }
      opens a RZ file ((|filename|)), mounts it as the directory ((|topdir|)),
      and returns its directory stream.
      If ((|topdir|)) is not given,
      it is determined automatically as 'lun1', 'lun2', and so on.
      open() can be called with a block.
      If a block is given, evaluates the block with the directory stream
      of the opened RZ file, and returns the result.
      The RZ file is closed automatically.

== methods:

--- RZFile#close
      closes the RZ file.
      If user accesses the closed RZ file, an exception is raised.
--- RZFile#filename
      returns the file name.
--- RZFile#lun
      returns the logical unit number of the file.
--- RZFile#option
      returns the option specified when the RZ file is opened.
--- RZFile#topname
      returns the directory name of the mount point.

=end
