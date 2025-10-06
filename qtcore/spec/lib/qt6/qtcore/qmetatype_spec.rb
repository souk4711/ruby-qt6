RSpec.describe RubyQt6::QtCore::QMetaType do
  it ".infer" do
    [
      [true, described_class::Type::Bool],
      [false, described_class::Type::Bool],
      [1234, described_class::Type::Int],
      [78.9, described_class::Type::Double],
      ["str", described_class::Type::QString],
      ["qstr", described_class::Type::QString],
      [RubyQt6::QtCore::QDateTime.current_date_time, described_class::Type::QDateTime],
      [RubyQt6::QtCore::QDate.current_date, described_class::Type::QDate],
      [RubyQt6::QtCore::QTime.current_time, described_class::Type::QTime],
      [RubyQt6::QtCore::QLine.new(0, 0, 1, 1), described_class::Type::QLine],
      [RubyQt6::QtCore::QLineF.new(0, 0, 1, 1), described_class::Type::QLineF],
      [RubyQt6::QtCore::QPoint.new(0, 0), described_class::Type::QPoint],
      [RubyQt6::QtCore::QPointF.new(0, 0), described_class::Type::QPointF],
      [RubyQt6::QtCore::QRect.new(0, 0, 1, 1), described_class::Type::QRect],
      [RubyQt6::QtCore::QRectF.new(0, 0, 1, 1), described_class::Type::QRectF],
      [RubyQt6::QtCore::QSize.new(0, 0), described_class::Type::QSize],
      [RubyQt6::QtCore::QSizeF.new(0, 0), described_class::Type::QSizeF]
    ].each do |(value, id)|
      o = described_class.infer(value)
      expect(o.id).to eq(id.to_i)
    end
  end
end
