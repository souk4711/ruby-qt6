# frozen_string_literal: true

class TetrixPiece
  NoShape = 0
  ZShape = 1
  SShape = 2
  LineShape = 3
  TShape = 4
  SquareShape = 5
  LShape = 6
  MirroredLShape = 7

  def initialize
    @coords_table = [
      [[0, 0], [0,  0], [0, 0], [0, 0]],
      [[0, -1], [0,  0], [-1, 0], [-1, 1]],
      [[0, -1], [0,  0], [1, 0], [1, 1]],
      [[0, -1], [0,  0], [0, 1], [0, 2]],
      [[-1, 0], [0, 0], [1, 0], [0, 1]],
      [[0,  0], [1,  0], [0, 1], [1, 1]],
      [[-1, -1], [0, -1], [0, 0], [0, 1]],
      [[1, -1], [0, -1], [0, 0], [0, 1]]
    ]
    @coords = [
      [0, 0], [0, 0], [0, 0], [0, 0]
    ]

    self.shape = NoShape
  end

  def x(index)
    @coords[index][0]
  end

  def y(index)
    @coords[index][1]
  end

  def set_x(index, x)
    @coords[index].[]=(0, x)
  end

  def set_y(index, y)
    @coords[index].[]=(1, y)
  end

  def set_random_shape
    self.shape = Kernel.rand(1..7)
  end

  def shape=(shape)
    (0...4).each do |i|
      (0...2).each do |j|
        @coords[i][j] = @coords_table[shape][i][j]
      end
    end
    @piece_shape = shape
  end

  attr_writer :piece_shape

  def shape
    @piece_shape
  end

  def min_x
    min = @coords[0][0]
    (1...4).each do |i|
      min = [min, @coords[i][0]].min
    end
    min
  end

  def max_x
    max = @coords[0][0]
    (1...4).each do |i|
      max = [max, @coords[i][0]].max
    end
    max
  end

  def min_y
    min = @coords[0][1]
    (1...4).each do |i|
      min = [min, @coords[i][1]].min
    end
    min
  end

  def max_y
    max = @coords[0][1]
    (1...4).each do |i|
      max = [max, @coords[i][1]].max
    end
    max
  end

  def rotated_left
    return self if @piece_shape == SquareShape

    result = TetrixPiece.new
    result.piece_shape = @piece_shape
    (0...4).each do |i|
      result.set_x(i, y(i))
      result.set_y(i, -x(i))
    end
    result
  end

  def rotated_right
    return self if @piece_shape == SquareShape

    result = TetrixPiece.new
    result.piece_shape = @piece_shape
    (0...4).each do |i|
      result.set_x(i, -y(i))
      result.set_y(i, x(i))
    end
    result
  end
end
