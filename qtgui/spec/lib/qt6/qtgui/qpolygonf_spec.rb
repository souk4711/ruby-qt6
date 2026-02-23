RSpec.describe RubyQt6::QtGui::QPolygonF do
  it "#initialize" do
    p = RubyQt6::QtCore::QPointF.new(1, 1)
    o = described_class.new << p
    expect(o.size).to eq(1)
    expect(o[0]).to eq(p)
  end
end
