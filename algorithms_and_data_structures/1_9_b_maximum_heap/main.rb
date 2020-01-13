h, w = gets.split(" ").to_i
box = []
string = gets.chomp

box << string
result = 0

position = Position.new
status = "right"

class Position
  attr_accessor :x, :y

  def initialize
    @x = 0
    @y = 0
    @direction = "right"
  end

  def change_direction(now_string)
    case now_string
    when "_"
      # do nothing
    when "/"
      case @direction
      when "right"
        @direction = "up"
      when "left"
        @direction = "down"
      when "up"
        @direction = "right"
      when "down"
        @direction = "left"
      end
    when "\\"
      case @direction
      when "right"
        @direction = "down"
      when "left"
        @direction = "up"
      when "up"
        @direction = "left"
      when "down"
        @direction = "right"
      end
    end
  end

  def next_position
    case @direction
    when "right"
      x += 1
    when "left"
      x -= 1
    when "up"
      y -= 1
    when "down"
      y += 1
    end
  end
end

while position.x >= 0 && position.x < w && position.y >= 0 && position.y < h do # さらに、0以上であることもかくにんする。
  now_string = box[position.y][position.x]
  position.change_direction(now_string)
  position.next_position

  result += 1
end

puts result
