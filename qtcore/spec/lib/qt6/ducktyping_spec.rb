RSpec.describe RubyQt6::T do
  it ".args_nth_delete_qobject" do
    o = RubyQt6::QtCore::QObject.new
    args = [o]
    expect(RubyQt6::T.args_nth_delete_qobject(args, -1)).to eq(o)
    expect(RubyQt6::T.args_nth_delete_qobject(args, -1)).to be_nil
  end

  it ".args_nth_delete_qwidget" do
  end

  it ".args_nth_to_qanystringview" do
    args = ["abc", "def".to_qstr]
    expect(RubyQt6::T.args_nth_to_qanystringview(args, 0)).to be_a(RubyQt6::QtCore::QAnyStringView)
    expect(RubyQt6::T.args_nth_to_qanystringview(args, 1)).to be_a(RubyQt6::QtCore::QAnyStringView)
    expect(RubyQt6::T.args_nth_to_qanystringview(args, 2)).to be_nil
  end

  it ".args_nth_to_qstr" do
    args = ["abc"]
    expect(RubyQt6::T.args_nth_to_qstr(args, 0)).to be_a(RubyQt6::QtCore::QString)
    expect(RubyQt6::T.args_nth_to_qstr(args, 1)).to be_nil
  end

  it ".to_qanystringview" do
    o1 = "abc"
    o2 = "def".to_qstr
    o3 = RubyQt6::QtCore::QAnyStringView.new("xyz")
    expect(RubyQt6::T.to_qanystringview(o1)).to be_a(RubyQt6::QtCore::QAnyStringView)
    expect(RubyQt6::T.to_qanystringview(o2)).to be_a(RubyQt6::QtCore::QAnyStringView)
    expect(RubyQt6::T.to_qanystringview(o3)).to be_a(RubyQt6::QtCore::QAnyStringView)
    expect(RubyQt6::T.to_qanystringview(o1).to_s).to eq("abc")
    expect(RubyQt6::T.to_qanystringview(o2).to_s).to eq("def")
    expect(RubyQt6::T.to_qanystringview(o3).to_s).to eq("xyz")
    expect(RubyQt6::T.to_qanystringview(12)).to eq(12)
  end

  it ".to_qstr" do
    o1 = "abc"
    o2 = "def".to_qstr
    expect(RubyQt6::T.to_qstr(o1)).to be_a(RubyQt6::QtCore::QString)
    expect(RubyQt6::T.to_qstr(o2)).to be_a(RubyQt6::QtCore::QString)
    expect(RubyQt6::T.to_qstr(o1)).to eq("abc")
    expect(RubyQt6::T.to_qstr(o2)).to eq("def")
    expect(RubyQt6::T.to_qstr(12)).to eq(12)
  end

  it ".to_qflags" do
    o1 = RubyQt6::QtCore::Qt::AlignmentFlag.new
    o2 = RubyQt6::QtCore::Qt::Alignment.new
    expect(RubyQt6::T.to_qflags(o1)).to be_a(RubyQt6::QtCore::Qt::Alignment)
    expect(RubyQt6::T.to_qflags(o2)).to be_a(RubyQt6::QtCore::Qt::Alignment)
    expect(RubyQt6::T.to_qflags(12)).to eq(12)
  end

  it ".bando_qobject_cast" do
  end
end
