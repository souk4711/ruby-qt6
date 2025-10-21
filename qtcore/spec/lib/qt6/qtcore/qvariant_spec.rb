RSpec.describe RubyQt6::QtCore::QVariant do
  it "bool" do
    o = described_class.from_bool(true)
    expect(o.type_name).to eq("bool")
    expect(o.value).to eq(true)
  end

  it "int" do
    o = described_class.from_int(1234)
    expect(o.type_name).to eq("int")
    expect(o.value).to eq(1234)
  end

  it "double" do
    o = described_class.from_double(12.34)
    expect(o.type_name).to eq("double")
    expect(o.value).to eq(12.34)
  end

  it "QString" do
    o = described_class.from_qstring("abc")
    expect(o.type_name).to eq("QString")
    expect(o.value).to eq("abc")

    o = described_class.from_qstring(RubyQt6::QtCore::QString.new("abc"))
    expect(o.type_name).to eq("QString")
    expect(o.value).to eq("abc")
  end

  it "QDateTime" do
    o = described_class.from_qdatetime(RubyQt6::QtCore::QDateTime.current_date_time)
    expect(o.type_name).to eq("QDateTime")
    expect(o.value).to be_a(RubyQt6::QtCore::QDateTime)
  end

  it "QDate" do
    o = described_class.from_qdate(RubyQt6::QtCore::QDate.current_date)
    expect(o.type_name).to eq("QDate")
    expect(o.value).to be_a(RubyQt6::QtCore::QDate)
  end

  it "QTime" do
    o = described_class.from_qtime(RubyQt6::QtCore::QTime.current_time)
    expect(o.type_name).to eq("QTime")
    expect(o.value).to be_a(RubyQt6::QtCore::QTime)
  end

  it "QLine" do
    o = described_class.from_qline(RubyQt6::QtCore::QLine.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QLine")
    expect(o.value).to be_a(RubyQt6::QtCore::QLine)
  end

  it "QLineF" do
    o = described_class.from_qlinef(RubyQt6::QtCore::QLine.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QLineF")
    expect(o.value).to be_a(RubyQt6::QtCore::QLineF)

    o = described_class.from_qlinef(RubyQt6::QtCore::QLineF.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QLineF")
    expect(o.value).to be_a(RubyQt6::QtCore::QLineF)
  end

  it "QPoint" do
    o = described_class.from_qpoint(RubyQt6::QtCore::QPoint.new(0, 0))
    expect(o.type_name).to eq("QPoint")
    expect(o.value).to be_a(RubyQt6::QtCore::QPoint)
  end

  it "QPointF" do
    o = described_class.from_qpointf(RubyQt6::QtCore::QPoint.new(0, 0))
    expect(o.type_name).to eq("QPointF")
    expect(o.value).to be_a(RubyQt6::QtCore::QPointF)

    o = described_class.from_qpointf(RubyQt6::QtCore::QPointF.new(0, 0))
    expect(o.type_name).to eq("QPointF")
    expect(o.value).to be_a(RubyQt6::QtCore::QPointF)
  end

  it "QRect" do
    o = described_class.from_qrect(RubyQt6::QtCore::QRect.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QRect")
    expect(o.value).to be_a(RubyQt6::QtCore::QRect)
  end

  it "QRectF" do
    o = described_class.from_qrectf(RubyQt6::QtCore::QRect.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QRectF")
    expect(o.value).to be_a(RubyQt6::QtCore::QRectF)

    o = described_class.from_qrectf(RubyQt6::QtCore::QRectF.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QRectF")
    expect(o.value).to be_a(RubyQt6::QtCore::QRectF)
  end

  it "QSize" do
    o = described_class.from_qsize(RubyQt6::QtCore::QSize.new(0, 0))
    expect(o.type_name).to eq("QSize")
    expect(o.value).to be_a(RubyQt6::QtCore::QSize)
  end

  it "QSizeF" do
    o = described_class.from_qsizef(RubyQt6::QtCore::QSize.new(0, 0))
    expect(o.type_name).to eq("QSizeF")
    expect(o.value).to be_a(RubyQt6::QtCore::QSizeF)

    o = described_class.from_qsizef(RubyQt6::QtCore::QSizeF.new(0, 0))
    expect(o.type_name).to eq("QSizeF")
    expect(o.value).to be_a(RubyQt6::QtCore::QSizeF)
  end

  it "QStringList" do
    o = described_class.from_qstringlist(RubyQt6::QtCore::QStringList.new)
    expect(o.type_name).to eq("QStringList")
    expect(o.value).to be_a(RubyQt6::QtCore::QStringList)
  end
end
