n,x,*a=`dd`.split.map &:to_i
d=(0..n).select{_1.digits-a==[]}
puts d[0]?d*' ''NONE'