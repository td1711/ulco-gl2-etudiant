module Lib where

mysqrt :: Double -> Maybe Double
mysqrt x = if x >= 0 then
    Just (sqrt x)
    else
        Nothing
