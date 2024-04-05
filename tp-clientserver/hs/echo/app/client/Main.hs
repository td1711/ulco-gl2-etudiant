{-# LANGUAGE OverloadedStrings #-}

import Control.Monad (forever)
import qualified Data.Text.IO as T
import qualified Network.WebSockets as WS

main :: IO ()
main = 
    WS.runClient "0.0.0.0" 9000 "" handleConn
    -- WS.runClient "ws.ifelse.io" 80 "" handleConn

handleConn :: WS.Connection -> IO ()
handleConn conn = do
    msg0 <- WS.receiveDataMessage conn
    T.putStrLn (WS.fromDataMessage msg0)
    forever $ do
        putStrLn "\nto server: "
        msgToSrv <- T.getLine
        if msgToSrv == ""
        then putStrLn "bye"
        else do
            WS.sendTextData conn msgToSrv
            msgFromSrv <- WS.receiveDataMessage conn
            putStrLn "from server: "
            T.putStrLn (WS.fromDataMessage msgFromSrv)

