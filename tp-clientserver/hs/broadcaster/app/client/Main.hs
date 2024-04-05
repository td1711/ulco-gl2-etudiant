{-# LANGUAGE OverloadedStrings #-}

import qualified Data.Text.IO as T
import qualified Network.WebSockets as WS

main :: IO ()
main = WS.runClient "0.0.0.0" 9000 "" handleConn

handleConn :: WS.Connection -> IO ()
handleConn conn = do
    msgFromSrv <- WS.receiveDataMessage conn
    T.putStrLn $ WS.fromDataMessage msgFromSrv
    handleConn conn

