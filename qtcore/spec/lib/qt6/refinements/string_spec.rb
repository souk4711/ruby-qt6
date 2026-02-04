RSpec.describe String do
  it "#o_qstr" do
    o = "abc".to_qstr
    expect(o).to be_a(QString)
    expect(o).to eq("abc")
  end
end
