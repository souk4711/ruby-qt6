RSpec.describe QMetaType do
  it ".infer" do
    [
      [true, described_class::Type::Bool],
      [false, described_class::Type::Bool],
      [1234, described_class::Type::Int],
      [78.9, described_class::Type::Double],
      ["str", described_class::Type::QString],
      ["qstr", described_class::Type::QString],
      [QDateTime.current_date_time, described_class::Type::QDateTime],
      [QDate.current_date, described_class::Type::QDate],
      [QTime.current_time, described_class::Type::QTime],
      [QLine.new(0, 0, 1, 1), described_class::Type::QLine],
      [QLineF.new(0, 0, 1, 1), described_class::Type::QLineF],
      [QPoint.new(0, 0), described_class::Type::QPoint],
      [QPointF.new(0, 0), described_class::Type::QPointF],
      [QRect.new(0, 0, 1, 1), described_class::Type::QRect],
      [QRectF.new(0, 0, 1, 1), described_class::Type::QRectF],
      [QSize.new(0, 0), described_class::Type::QSize],
      [QSizeF.new(0, 0), described_class::Type::QSizeF]
    ].each do |(value, id)|
      o = described_class.infer(value)
      expect(o.id).to eq(id.to_i)
    end
  end
end
