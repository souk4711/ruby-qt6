RSpec.describe QVariant do
  it ".from_bool" do
    o = described_class.new(true)
    expect(o.type_name).to eq("bool")
    expect(o.value).to eq(true)
  end

  it ".from_int" do
    o = described_class.new(1234)
    expect(o.type_name).to eq("int")
    expect(o.value).to eq(1234)
  end

  it ".from_double" do
    o = described_class.new(12.34)
    expect(o.type_name).to eq("double")
    expect(o.value).to eq(12.34)
  end

  it ".from_qstring" do
    o = described_class.new("abc")
    expect(o.type_name).to eq("QString")
    expect(o.value).to eq("abc")

    o = described_class.new(QString.new("abc"))
    expect(o.type_name).to eq("QString")
    expect(o.value).to eq("abc")
  end

  it ".from_qdatetime" do
    o = described_class.new(QDateTime.current_date_time)
    expect(o.type_name).to eq("QDateTime")
    expect(o.value).to be_a(QDateTime)
  end

  it ".from_qdate" do
    o = described_class.new(QDate.current_date)
    expect(o.type_name).to eq("QDate")
    expect(o.value).to be_a(QDate)
  end

  it ".from_qtime" do
    o = described_class.new(QTime.current_time)
    expect(o.type_name).to eq("QTime")
    expect(o.value).to be_a(QTime)
  end

  it ".from_qline" do
    o = described_class.new(QLine.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QLine")
    expect(o.value).to be_a(QLine)
  end

  it ".from_qlinef" do
    o = described_class.new(QLine.new(0, 0, 1, 1), QLineF.default_qmetatype)
    expect(o.type_name).to eq("QLineF")
    expect(o.value).to be_a(QLineF)

    o = described_class.new(QLineF.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QLineF")
    expect(o.value).to be_a(QLineF)
  end

  it ".from_qpoint" do
    o = described_class.new(QPoint.new(0, 0))
    expect(o.type_name).to eq("QPoint")
    expect(o.value).to be_a(QPoint)
  end

  it ".from_qpointf" do
    o = described_class.new(QPoint.new(0, 0), QPointF.default_qmetatype)
    expect(o.type_name).to eq("QPointF")
    expect(o.value).to be_a(QPointF)

    o = described_class.new(QPointF.new(0, 0))
    expect(o.type_name).to eq("QPointF")
    expect(o.value).to be_a(QPointF)
  end

  it ".from_qrect" do
    o = described_class.new(QRect.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QRect")
    expect(o.value).to be_a(QRect)
  end

  it ".from_qrectf" do
    o = described_class.new(QRect.new(0, 0, 1, 1), QRectF.default_qmetatype)
    expect(o.type_name).to eq("QRectF")
    expect(o.value).to be_a(QRectF)

    o = described_class.new(QRectF.new(0, 0, 1, 1))
    expect(o.type_name).to eq("QRectF")
    expect(o.value).to be_a(QRectF)
  end

  it ".from_qsize" do
    o = described_class.new(QSize.new(0, 0))
    expect(o.type_name).to eq("QSize")
    expect(o.value).to be_a(QSize)
  end

  it ".from_qsizef" do
    o = described_class.new(QSize.new(0, 0), QSizeF.default_qmetatype)
    expect(o.type_name).to eq("QSizeF")
    expect(o.value).to be_a(QSizeF)

    o = described_class.new(QSizeF.new(0, 0))
    expect(o.type_name).to eq("QSizeF")
    expect(o.value).to be_a(QSizeF)
  end

  it ".from_qstringlist" do
    o = described_class.new(QStringList.new)
    expect(o.type_name).to eq("QStringList")
    expect(o.value).to be_a(QStringList)
  end

  it ".from_qvariant" do
    o1 = described_class.new("str")
    expect(o1).to be_a(described_class)

    o2 = described_class.new(o1)
    expect(o2).to eq(o1)
  end
end
